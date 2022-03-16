import Foundation
@objc(SingleCharWidgetManager)
class SingleCharWidgetManager : RCTViewManager {
  override func view() -> UIView! {
    return SingleCharWidget();
  }
}
