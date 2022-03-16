// Copyright MyScript. All rights reserved.

#import <UIKit/UIKit.h>

#import <ATKIMCommon/IMCandidateInfo.h>
#import <ATKIMCommon/IMCaptureInfo.h>

@protocol SCWSingleCharWidgetDelegate;

/** Single character widget interface.
 * @throws IllegalStateException if MyScript engine certificate has not been
 * registered or is invalid.
 * @see registerCertificate:
 */
@interface SCWSingleCharWidget : UIView

/** Delegate.
 */
@property (nonatomic, weak) id<SCWSingleCharWidgetDelegate> delegate;

// ----------------------------------------------------------------------
#pragma mark - Widget configuration

/** Register MyScript engine certificate.
 * @param certificate Certificate to register.
 * @return <code>YES</code> on success, <code>NO</code> on failure.
 */
- (BOOL) registerCertificate:(NSData *)certificate;

/** Color of the ink.
 */
@property (nonatomic, readwrite) UIColor *inkColor;

/** Width of the ink.<br />
 * min = 1<br />
 * max = 25<br />
 * default = 7
 */
@property (nonatomic, readwrite) CGFloat inkWidth;

/** Fade-out effect options */
typedef NSUInteger SCWInkFadeOutEffect;
enum {
  /** Automatic selection of fade-out effect (default mode) */
  SCWInkFadeOutEffectAuto = 0,
  /** 
   * No fade-out effect on a stroke basis, all strokes are faded out on freeze event.
   * This mode is recommended for cursive and isolated handwriting recognition.
   */
  SCWInkFadeOutEffectNone = 1,
  /** 
   * Fade-out each individual stroke after the configured fade-out delay.
   * This mode is recommended for superimposed handwriting recognition
   * of latin, cyrillic and Korean scripts.
   */
  SCWInkFadeOutEffectAfterDelay = 2,
  /** 
   * Fade-out each individual stroke by a specified amount on pen up event.
   * This mode is recommended for superimposed handwriting recognition
   * of Chinese and Japanese scripts.
   */
  SCWInkFadeOutEffectOnPenUp = 3,
};

/** Set the ink fade-out effect <br />
 * Fade-out effect type or -1 to revert to default value.
 *
 * <ul>
 *   <li>Automatic selection of fade-out effect (default mode): SCWInkFadeOutEffectAuto = 0</li>
 *   <li>No fade-out effect on a stroke basis, all strokes are faded out on freeze event.
 * This mode is recommended for cursive and isolated handwriting recognition: SCWInkFadeOutEffectNone = 1</li>
 *   <li>Fade-out each individual stroke after the configured fade-out delay.
 * This mode is recommended for superimposed handwriting recognition
 * of latin, cyrillic and Korean scripts: SCWInkFadeOutEffectAfterDelay = 2</li>
 *   <li>Fade-out each individual stroke by a specified amount on pen up event.
 * This mode is recommended for superimposed handwriting recognition
 * of Chinese and Japanese scripts: SCWInkFadeOutEffectOnPenUp = 3</li>
 * </ul>
 *
 * @see inkFadeOutDelay(NSTimeInterval)
 * @see inkFadeOutDuration(NSTimeInterval)
 * @see inkFadeOutTo(CGFloat)
 * @see inkFadeOutStep(CGFloat)
 */
@property (nonatomic, readwrite) SCWInkFadeOutEffect inkFadeOutEffect;

/** Delay in milliseconds after which strokes start fading out or -1 to revert to default value.<br />
 * min = 100 ms<br />
 * max = 10000 ms<br />
 * default = 400 ms
 */
@property (nonatomic, readwrite) double inkFadeOutDelay;

/** Duration in milliseconds of the strokes fade-out animation or -1 to revert to default value.<br />
 * min = 100 ms<br />
 * max = 10000 ms<br />
 * default = 400 ms
 */
@property (nonatomic, readwrite) double inkFadeOutDuration;

/** Target alpha value of the strokes fade-out animation or -1 to revert to default value.<br />
 * min = 0.0f<br />
 * max = 1.0f<br />
 * default = 0.1f
 */
@property (nonatomic, readwrite) CGFloat inkFadeOutTo;

/** Amount of alpha faded out after each pen-up event or -1 to revert to default value.<br />
 * min = 0.0f<br />
 * max = 1.0f<br />
 * default = 0.15f
 */
@property (nonatomic, readwrite) CGFloat inkFadeOutStep;

/** Enable or disable auto-commit feature.<br />
 * Enable auto-commit if <code>YES</code>, disable if <code>NO</code>.
 */
@property (nonatomic, readwrite) BOOL autoCommitEnabled;

/** Delay in milliseconds after which auto-commit is triggered or -1 to revert to default value.<br />
 * min = 100 ms<br />
 * max = 10000 ms<br />
 * default = 500 ms
 */
@property (nonatomic, readwrite) double autoCommitDelay;

/** Delay in milliseconds after which auto-freeze is triggered or -1 to revert to default value.<br />
 * min = 100 ms<br />
 * max = 10000 ms<br />
 * default = 1500 ms
 */
@property (nonatomic, readwrite) double autoFreezeDelay;

/** Delay in milliseconds after which long press event is triggered or -1 to revert to default value.<br />
 * min = 100 ms<br />
 * max = 10000 ms<br />
 * default = 500 ms
 */
@property (nonatomic, readwrite) double longPressDelay;

/** Maximum number of word candidates.<br />
 * Widget must be configured again for this setting to take effect.<br />
 * Set to -1 to use the value from the .lang configuration file.<br />
 * min = 1<br />
 * max = 20<br />
 * default = 1<br />
 * initial = -1
 */
@property (nonatomic, readwrite) NSInteger wordCandidateListSize;

/** Maximum number of word completion candidates.<br />
 * Widget must be configured again for this setting to take effect.<br />
 * Set to -1 to use the value from the .lang configuration file.<br />
 * min = 0<br />
 * max = 20<br />
 * default = 0<br />
 * initial = -1
 */
@property (nonatomic, readwrite) NSInteger wordCompletionCandidateListSize;

/** Maximum number of word prediction candidates.<br />
 * Widget must be configured again for this setting to take effect.<br />
 * Set to -1 to use the value from the .lang configuration file.<br />
 * min = 0<br />
 * max = 20<br />
 * default = 0<br />
 * initial = -1
 */
@property (nonatomic, readwrite) NSInteger wordPredictionCandidateListSize;

/** Maximum number of character candidates.<br />
 * Widget must be configured again for this setting to take effect.<br />
 * Set to -1 to use the value from the .lang configuration file.<br />
 * min = 1<br />
 * max = 20<br />
 * default = 1<br />
 * initial = -1
 */
@property (nonatomic, readwrite) NSInteger characterCandidateListSize;

/** Speed/quality compromise rating.<br />
 * Widget must be configured again for this setting to take effect.<br />
 * Set to -1 to use the value from the .lang configuration file.<br />
 * min = 0<br />
 * max = 255<br />
 * initial = -1
 *
 * <p>
 * Higher value give better accuracy but reduce recognition speed<br />
 * Lower value improve recognition speed but accuracy is lower
 */
@property (nonatomic, readwrite) int speedQualityCompromise;

/** User lexicon (array of user-defined words).<br />
 * Widget must be configured again for this setting to take effect.
 */
@property (nonatomic, readwrite) NSArray *userLexicon;

/** Enable or disable auto-space feature.<br />
 * Widget must be configured again for this setting to take effect.
 * <b>Note that this feature is only available for Asian languages
 * (Chinese, Japanese and Korean) in superimposed handwriting mode.</b><br />
 * Enable auto-space if <code>YES</code>, disable if <code>NO</code>.
 */
@property (nonatomic, readwrite) BOOL autoSpaceEnabled;

/** Recognition mode options with the appropriates resources */
typedef NSUInteger SCWRecognitionMode;
enum {
  /** Automatic selection of recognition mode from configured resources (default) */
  SCWRecognitionModeAuto = 0,
  /** Superimposed recognition mode */
  SCWRecognitionModeSuperimposed = 1,
  /** Isolated recognition mode */
  SCWRecognitionModeIsolated = 2,
  /** Cursive recognition mode with multi-line support */
  SCWRecognitionModeCursive = 3,
};

/** Handwriting recognition mode
 * <ul>
 *   <li>Automatic selection of recognition mode from configured resources (default): SCWRecognitionModeAuto = 0</li>
 *   <li>Superimposed recognition mode: SCWRecognitionModeSuperimposed = 1</li>
 *   <li>Isolated recognition mode: SCWRecognitionModeIsolated = 2</li>
 *   <li>Cursive recognition mode with multi-line support: SCWRecognitionModeCursive = 3</li>
 * </ul>
 */
@property (nonatomic, readwrite) SCWRecognitionMode recognitionMode;

// ----------------------------------------------------------------------
#pragma mark - Transliteration

/** Enable or disable transliteration feature.<br />
 * Widget must be configured again for this setting to take effect.<br />
 * Enable transliteration if <code>YES</code>,
 * disable if <code>NO</code>.
 */
@property (nonatomic, readwrite) BOOL transliterationEnabled;

// ----------------------------------------------------------------------
#pragma mark - Gestures

/** Gesture flags */
enum {
  /** All gestures. */
  SCWGestureAllGestures   = 0xffffffff,
  /** Single tap gesture */
  SCWGestureSingleTap     = 0x00000001,
  /** Long press gesture */
  SCWGestureLongPress     = 0x00000002,
  /** Backspace gesture */
  SCWGestureBackspace     = 0x00000004,
  /** Return gesture */
  SCWGestureReturn        = 0x00000008,
  /** Space gesture */
  SCWGestureSpace         = 0x00000010,
};

/** Enable detection of the specified gesture.<br />
 * Several gestures may be enabled at once by combining
 * several gesture flags using an OR operation.
 * @param gesture Gesture(s) to enable.
 * <p>
 * All gestures: SCWGestureAllGestures = 0xffffffff<br>
 * Single tap gesture: SCWGestureSingleTap = 0x00000001<br>
 * Long press gesture: SCWGestureLongPress = 0x00000002<br>
 * Backspace gesture: SCWGestureBackspace = 0x00000004<br>
 * Return gesture: SCWGestureReturn = 0x00000008<br>
 * Space gesture: SCWGestureSpace = 0x00000010<br>
 * <p>
 * The <code>mul-lk-gesture.res</code> handwriting resource
 * is required to be able to detect gestures and must be added
 * to the configuration script of the <code>.lang</code> file
 * used during configuration.
 */
- (void) enableGesture:(int)gesture;

/** Disable detection of the specified gesture.<br />
 * Several gestures may be enabled at once by combining
 * several gesture flags using an OR operation.
 * @param gesture Gesture(s) to disable.
 *
 * @see enableGesture:
 */
- (void) disableGesture:(int)gesture;

/** Return whether specified gesture is enabled.
 * @param gesture Gesture flag.
 * @return <code>YES</code> if gesture is enabled,
 * <code>NO</code> otherwise.
 *
 * @see enableGesture:
 */
- (BOOL) gestureEnabled:(int)gesture;

// ----------------------------------------------------------------------
#pragma mark - Text management

/** Clear ink and text contained in the widget.
 */
- (void) clear;

/** Text managed by this widget.
 */
@property (nonatomic, readwrite) NSString *text;

/** Replace characters in the text.
 * This method can be used to select an alternate handwriting
 * recognition candidate for any word or character. The specified
 * character range shall span a word or a single character, and the
 * provided replacement text shall be one of the possible candidates
 * to trigger a word or character candidate change.
 * <p>
 * Characters may be inserted at any location in the text by calling
 * this method with the same start and end character indices and a
 * non-empty replacement string.
 * <p>
 * Characters may be deleted from the text by calling this method
 * with a non-empty characters range and an empty or <code>nil</code>
 * replacement string.
 *
 * @param range Range of characters to replace.
 * @param text Replacement text string (may be <code>nil</code>).
 * @return <code>YES</code> if the operation has been applied,
 * <code>NO</code> if the index range is invalid or the widget is
 * busy processing.
 *
 * @see wordCandidatesAtIndex:
 * @see characterCandidatesAtIndex:
 */
- (BOOL) replaceCharactersInRange:(NSRange)range withText:(NSString *)text;

/** Return alternate candidate info for the word at specified index.
 * This method computes the character range of the word at specified
 * index, and provides alternate candidates and possible completions.
 * <p>
 * Alternate candidates can be selected by calling the
 * replaceCharactersInRange:withText: method with
 * parameters from the candidate information object.
 *
 * @param index Character index within or before the word.
 * @return Candidate information for the word at specified index
 * or <code>nil</code> if index is out of bounds.
 *
 * @see IMCandidateInfo
 * @see replaceCharactersInRange:withText:
 */
- (IMCandidateInfo *) wordCandidatesAtIndex:(NSInteger)index;

/** Return alternate candidate info for the character at specified index.
 * This method computes the character range of the character at specified
 * index, and provides alternate candidates.
 * <p>
 * Alternate candidates can be selected by calling the
 * replaceCharactersInRange:withText: method with
 * parameters from the candidate information object.
 *
 * @param index Character index within or before the character.
 * @return Candidate information for the character at specified index
 * or <code>nil</code> if index is out of bounds.
 *
 * @see IMCandidateInfo
 * @see replaceCharactersInRange:withText:
 */
- (IMCandidateInfo *) characterCandidatesAtIndex:(NSInteger)index;

// ----------------------------------------------------------------------
#pragma mark - Commit

/** Commit the current writing session, optionally clear ink from the screen.
 * This method commits the current writing session if not empty
 * and starts a new one. If the current writing session is empty,
 * the widget does not start a new one.
 * <p>
 * The meaning of a writing session depends on the current handwriting
 * recognition mode.
 * <ul>
 *  <li>In <b>superimposed</b> mode, a writing session represents
 *  any kind of text (from a single character up to several sentences)
 *  with each character written on top of the other. A commit operation
 *  freezes all strokes and text interpretation, keeps them and starts
 *  a new writing session.</li>
 *  <li>In <b>isolated</b> mode, a writing session represents a single
 *  character. A commit operation indicates the end of the current
 *  character and starts the next one.</li>
 *  <li>In <b>cursive</b> mode, a writing session is a single screen page,
 *  which represents from a single character up to several words and
 *  sentences, laid out on a single or multiple lines. A commit operation
 *  indicates the end of the current screen page and starts the
 *  next one.</li>
 * </ul>
 * <p>
 * Strokes currently displayed on the screen are either kept or removed
 * from the screen based on the value of the <code>clearInk</code>
 * parameter.
 * <p>
 * <b>This method may be ignored if the widget is not configured, as
 * the recognition mode could not be automatically detected and this
 * information is required.
 * If you plan on using this API before widget is configured, please
 * consider setting the recognition mode explicitly using the provided
 * API method.</b>
 *
 * @param clearInk Clear ink from the screen if <code>YES</code>, keep
 * ink if <code>NO</code>.
 *
 * @see autoCommitEnabled
 * @see autoCommitDelay
 * @see recognitionMode
 */
- (void) commitAndClearInk:(BOOL)clearInk;

// ----------------------------------------------------------------------
#pragma mark - Insertion point

/** Character index of the insertion point in the text.
 */
@property (nonatomic, readwrite) NSUInteger insertIndex;

/** Insert the given string at the insertion point.
 * This method inserts the given string into the input stream of the
 * handwriting recognizer without freezing strokes. This method
 * is particularly useful when implementing space or any other button.
 * <p>
 * <b>This method may be ignored if the widget is not configured, as
 * the recognition mode could not be automatically detected and this
 * information is required.
 * If you plan on using this API before widget is configured, please
 * consider setting the recognition mode explicitly using the provided
 * API method.</b>
 *
 * @param string String to insert at the insertion point.
 * @see insertIndex
 * @see recognitionMode
 */
- (void) insertString:(NSString *)string;

// ----------------------------------------------------------------------
#pragma mark - Handwriting configuration

/** Clear handwriting resources search path.
 */
- (void) clearSearchPath;

/** Add given directory to handwriting resources search path.<br />
 * Directory name can point to a folder in the file system, or to a
 * directory in a zip file. Handwriting resources can be loaded directly
 * from the bundle folder @see configureWithBundle:andConfig:
 *
 * @param directoryName Path to a folder containing handwriting resources.
 */
- (void) addSearchDir:(NSString *)directoryName;

/** Configure handwriting recognition engine.
 * This method is non-blocking and returns immediately.
 * <p>
 * Configuration is a lengthy process that may take up to several
 * seconds, depending on the handwriting resources to be configured.
 * It is recommended to setup a configuration listener to detect the end
 * of the configuration process.
 *
 * @param bundleName Name of the configuration bundle (for example, "en-US").
 * @param configName Name of the configuration mode (for example, "text").
 *
 * @see clearSearchPath
 * @see addSearchDir:
 */
- (void) configureWithBundle:(NSString *)bundleName andConfig:(NSString *)configName;

/** String describing the last configuration error.
 */
@property (nonatomic, readonly) NSString *errorString;

/** Error codes<br />
 * No error: SCWErrorCodeNoError<br />
 * Invalid certificate: SCWErrorCodeInvalidCertificate<br />
 * Invalid API key: SCWErrorCodeInvalidAPIKey<br />
 * Cannot load handwriting resource: SCWErrorCodeCannotLoadHandwritingResource<br />
 * Cannot create user lexicon resource: SCWErrorCodeCannotCreateUserLexiconResource<br />
 * Cannot create subset knowledge resource: SCWErrorCodeCannotCreateSubsetKnowledgeResource<br />
 * Error setting internal property: SCWErrorCodeCannotSetProperty<br />
 */
typedef NSUInteger SCWErrorCode;
enum {
  /** No error */
  SCWErrorCodeNoError = 0,
  /** Invalid certificate */
  SCWErrorCodeInvalidCertificate = 1,
  /** Invalid API key */
  SCWErrorCodeInvalidAPIKey = 2,
  /** Cannot load handwriting resource */
  SCWErrorCodeCannotLoadHandwritingResource = 3,
  /** Cannot create user lexicon resource */
  SCWErrorCodeCannotCreateUserLexiconResource = 4,
  /** Cannot create subset knowledge resource */
  SCWErrorCodeCannotCreateSubsetKnowledgeResource = 5,
  /** Error setting internal property */
  SCWErrorCodeCannotSetProperty = 6,
};

/** Error code describing the error.
 * <p>
 * No error: SCWErrorCodeNoError = 0<br />
 * Invalid certificate: SCWErrorCodeInvalidCertificate = 1<br />
 * Invalid API key: SCWErrorCodeInvalidAPIKey = 2<br />
 * Cannot load handwriting resource: SCWErrorCodeCannotLoadHandwritingResource = 3<br />
 * Cannot create user lexicon resource: SCWErrorCodeCannotCreateUserLexiconResource = 4<br />
 * Cannot create subset knowledge resource: SCWErrorCodeCannotCreateSubsetKnowledgeResource = 5<br />
 * Error setting internal property: SCWErrorCodeCannotSetProperty = 6<br />
 */
@property (nonatomic, readonly) SCWErrorCode errorCode;

// ----------------------------------------------------------------------
#pragma mark - Ink Management

/** Add a stroke to the widget.
 * @param listCaptureInfo List of capture information.
 * @see IMCaptureInfo
 */
- (void)addStroke:(NSArray*)listCaptureInfo;

/** Simulate a pen down event.
 * This simulates a user that starts writing.
 * @param captureInfo Capture information.
 */
- (void)penDown:(IMCaptureInfo*)captureInfo;

/** Simulate a pen up event.
 * This simulates a user that ends writing.
 * @param captureInfo Capture information.
 */
- (void)penUp:(IMCaptureInfo*)captureInfo;

/** Simulate a pen move event.
 * This simulates a user writing.
 * @param captureInfo Capture information.
 */
- (void)penMove:(IMCaptureInfo*)captureInfo;

/** Simulate a pen abort event.
 * This simulates a user writing.
 */
- (void)penAbort;

@end
