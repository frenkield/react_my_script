#import "AppDelegate.h"

#import <React/RCTBundleURLProvider.h>
#import <React/RCTRootView.h>
#import <React/RCTLog.h>

@interface AppDelegate ()
@property (strong, nonatomic) NSString *singleCharWidgetSearchDir;
@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  NSURL *jsCodeLocation;

  jsCodeLocation = [[RCTBundleURLProvider sharedSettings] jsBundleURLForBundleRoot:@"index" fallbackResource:nil];

  RCTRootView *rootView = [[RCTRootView alloc] initWithBundleURL:jsCodeLocation
                                                      moduleName:@"crossword"
                                               initialProperties:nil
                                                   launchOptions:launchOptions];
                                                   
  rootView.backgroundColor = [[UIColor alloc] initWithRed:1.0f green:1.0f blue:1.0f alpha:1];

  self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
  UIViewController *rootViewController = [UIViewController new];
  rootViewController.view = rootView;
  self.window.rootViewController = rootViewController;
  [self.window makeKeyAndVisible];
  
  [self initializeSingleCharWidgetSearchDir];

  return YES;
}

- (void)initializeSingleCharWidgetSearchDir {
  
  NSBundle *mainBundle = [NSBundle mainBundle];
  NSString *bundlePath = [mainBundle pathForResource:@"single-char-widget-resources" ofType:@"bundle"];
  self.singleCharWidgetSearchDir = [bundlePath stringByAppendingPathComponent:@"conf"];
  RCTLogInfo(@"initializing search dir: %@", self.singleCharWidgetSearchDir);
}


@end
