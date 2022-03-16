import UIKit

class SingleCharWidget: UIView, SCWSingleCharWidgetDelegate {
  
  var currentPath = UIBezierPath()
  var scale = CGFloat(1)
  let label = UILabel()
  
  // TODO - find a non-hacky way to share the widget
  
  static var singleCharWidgetWidth = 200
  static var singleCharWidgetHeight = 200
  
  static var singleCharWidget = SCWSingleCharWidget(
    frame: CGRect(x: 0, y: 0, width: singleCharWidgetWidth, height: singleCharWidgetHeight)
  )

  static var initialized = false
  
  override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
    
    super.touchesBegan(touches, with: event)

    // TODO - find a non-hacky way to share the widget
    SingleCharWidget.singleCharWidget.delegate = self;

    if let touch = touches.first {

      let point = touch.location(in: self)
      moveToPoint(point)
      
      SingleCharWidget.singleCharWidget.penDown(generateScaledCaptureInfo(point))
    }
  }
  
  override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
    
    super.touchesMoved(touches, with: event);

    if let touch = touches.first {
      
      let point = touch.location(in: self)
      addPoint(point)

      SingleCharWidget.singleCharWidget.penMove(generateScaledCaptureInfo(point))
    }
  }
  
  override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {

    super.touchesEnded(touches, with: event);

    if let touch = touches.first {

      let point = touch.location(in: self)
      addPoint(point)
      
      SingleCharWidget.singleCharWidget.penUp(generateScaledCaptureInfo(point))
    }
  }
  
  override func touchesCancelled(_ touches: Set<UITouch>, with event: UIEvent?) {
    super.touchesCancelled(touches, with: event);
    print("******** touchesCancelled *********");
  }
  
  override func touchesEstimatedPropertiesUpdated(_ touches: Set<UITouch>) {
    super.touchesEstimatedPropertiesUpdated(touches);
    print("******** touchesEstimatedPropertiesUpdated **********")
  }
  
  func singleCharWidget(_ sender: SCWSingleCharWidget!, didChangeText text: String!, intermediate: Bool) {

    print("didChangeText: ", text, intermediate);
    
    if (!intermediate) {

      currentPath = UIBezierPath()

      if (text != nil && text.count > 0) {
        let character = String(describing: text.last!)
        label.text = character
        SingleCharWidget.singleCharWidget.clear()

      } else {
 //       label.text = ""
      }
      
      setNeedsDisplay()
    }
  }

  func moveToPoint(_ point: CGPoint) {
    currentPath.move(to: point)
  }

  func addPoint(_ point: CGPoint) {
    currentPath.addLine(to: point)
    setNeedsDisplay()
  }

  func generateScaledCaptureInfo(_ point: CGPoint) -> IMCaptureInfo {
    let captureInfo = IMCaptureInfo()
    captureInfo.x = point.x * scale
    captureInfo.y = point.y * scale
    return captureInfo
  }
  
  override func draw(_ rect: CGRect) {
    
    label.frame = rect
    label.font = label.font.withSize(rect.width)

    super.draw(rect)
    currentPath.stroke()
  }

  static func initializeSingleCharWidget() {
    
    let certificate = NSData(bytes: myCertificate.bytes, length: myCertificate.length);
        let isRegistered = singleCharWidget.registerCertificate(certificate as Data!);
    
    if (!isRegistered) {
      print("****************** failed registerCertificate **************");
    }
    
    let app = UIApplication.shared.delegate as! AppDelegate
    let singleCharWidgetSearchDir = app.singleCharWidgetSearchDir;
    
    //        singleCharWidget.autoCommitEnabled = false
    //        singleCharWidget.autoCommitDelay = 10000
    //        singleCharWidget.autoFreezeDelay = 10000
    
    singleCharWidget.addSearchDir(singleCharWidgetSearchDir);
    singleCharWidget.configure(withBundle: "en_US", andConfig: "si_text");
    
    print("****************** initialized shared single char widget **************");
  }

  override func layoutSubviews() {
    
    super.layoutSubviews();
    scale = CGFloat(SingleCharWidget.singleCharWidgetWidth) / frame.width
    
    // TODO - find a non-hacky way to share the widget
    if (!SingleCharWidget.initialized) {
      SingleCharWidget.initialized = true
      SingleCharWidget.initializeSingleCharWidget()
    }
    
    label.textAlignment = NSTextAlignment.center
    addSubview(label)
  }
  
  override init(frame: CGRect) {
    super.init(frame: frame)
  }
  
  required init?(coder aDecoder: NSCoder) {
    fatalError("init(coder:) has not been implemented")
  }
}
