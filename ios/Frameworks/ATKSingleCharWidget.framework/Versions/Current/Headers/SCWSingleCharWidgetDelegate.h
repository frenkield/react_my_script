// Copyright MyScript. All rights reserved.

#import <UIKit/UIKit.h>

#import <ATKIMCommon/IMCaptureInfo.h>

@class SCWSingleCharWidget;

/**
 * Delegate.
 */
@protocol SCWSingleCharWidgetDelegate <NSObject>

@optional

/** Called when the text changes.
 * The text returned by this callback may be intermediate, which
 * means that it can change again in the near future. Text is
 * intermediate as long as the widget has some ink that has not been
 * processed yet.
 *
 * @param sender Widget for which text changes.
 * @param text String representation of the text.
 * @param intermediate <code>YES</code> if the text is an
 * intermediate handwriting recognition result, <code>NO</code>
 * if the text is stable.
 */
- (void)singleCharWidget:(SCWSingleCharWidget *)sender didChangeText:(NSString*)text intermediate:(BOOL)intermediate;

/** Called when a single tap gesture is detected.
 * The application may choose to take action when a single tap
 * gesture is detected, in this case this callback shall return
 * <code>YES</code> to indicate that it handled the event.
 * <p>
 * If this callback returns <code>NO</code>, then the single
 * tap gesture is considered by the widget as a genuine dot and
 * passed to the handwriting recognizer.
 * <p>
 * <b>This callback is called from a native thread, not from
 * the UI thread. You must not call any widget methods from this
 * callback, or the widget will enter a deadlock state.</b>
 *
 * @param sender Widget that has detected the gesture.
 * @param point CGPoint position of the single tap in widget coordinates.
 *
 * @return <code>YES</code> if single tap event is handled,
 * <code>NO</code> otherwise (indicates a handwritten dot).
 */
- (BOOL)singleCharWidget:(SCWSingleCharWidget*)sender didDetectSingleTapAtPoint:(CGPoint)point;

/** Called when a long press gesture is detected.
 * The application may choose to take action when a long press
 * gesture is detected, in this case this callback shall return
 * <code>YES</code> to indicate that it handled the event and the
 * current stroke is cancelled.
 * <p>
 * If this callback returns <code>NO</code>, then the long
 * press gesture is discarded by the widget and the widget resumes
 * the capture of the current stroke.
 * <p>
 * <b>This callback is called from a native thread, not from
 * the UI thread. You must not call any widget methods from this
 * callback, or the widget will enter a deadlock state.</b>
 *
 * @param sender Widget that has detected the gesture.
 * @param point CGPoint position of the single tap in widget coordinates.
 *
 * @return <code>YES</code> if long press event is handled,
 * <code>NO</code> otherwise.
 */
- (BOOL)singleCharWidget:(SCWSingleCharWidget*)sender didDetectLongPressAtPoint:(CGPoint)point;

/** Called when a backspace gesture is detected.
 * @param sender Widget that has detected the gesture.
 * @param index Character index at which gesture is detected.
 * @param count Number of consecutive detected backspace gestures.
 */
- (void)singleCharWidget:(SCWSingleCharWidget*)sender didDetectBackspaceAtIndex:(NSUInteger)index withCount:(NSUInteger)count;

/** Called when a return gesture is detected.
 * @param sender Widget that has detected the gesture.
 * @param index Character index at which gesture is detected.
 */
- (void)singleCharWidget:(SCWSingleCharWidget*)sender didDetectReturnAtIndex:(NSUInteger)index;

/** Called when handwriting configuration ends.
 * In case of failure, you may retrieve more information by calling
 * either [SCWSingleCharWidget errorCode] or [SCWSingleCharWidget errorString].
 *
 * @param sender Widget for which configuration is done.
 * @param success <code>YES</code> if configuration succeeded,
 * <code>NO</code> otherwise.
 */
- (void)singleCharWidget:(SCWSingleCharWidget*)sender didConfigureWithSuccess:(BOOL)success;

/** Called when the user starts writing.
 * @param sender Widget for which user starts writing.
 * @param captureInfo Coordinates and other information about touch sample.
 */
- (void)singleCharWidgetPenDown:(SCWSingleCharWidget*)sender didCaptureInfo:(IMCaptureInfo*)captureInfo;

/** Called when the user ends writing.
 * @param sender Widget for which user ends writing.
 * @param captureInfo Coordinates and other information about touch sample.
 */
- (void)singleCharWidgetPenUp:(SCWSingleCharWidget*)sender didCaptureInfo:(IMCaptureInfo*)captureInfo;

/** Called when the user is writing.
 * @param sender Widget for which user is writing.
 * @param captureInfo Coordinates and other information about touch sample.
 */
- (void)singleCharWidgetPenMove:(SCWSingleCharWidget*)sender didCaptureInfo:(IMCaptureInfo*)captureInfo;

/** Called when the user aborts writing.
 * @param sender Widget for which user aborts writing.
 */
- (void)singleCharWidgetPenAbort:(SCWSingleCharWidget*)sender;

@end
