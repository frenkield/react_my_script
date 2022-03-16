// Copyright MyScript. All rights reserved.

#import <UIKit/UIKit.h>

/**
 * Interface CaptureInfo.
 */
@interface IMCaptureInfo : NSObject {
  CGFloat               _x;
  CGFloat               _y;
  CGFloat               _f;
  CGFloat               _w;
  NSTimeInterval        _t;
}

/** X coordinate of the point. */
@property (nonatomic, readwrite) CGFloat             x;
/** Y coordinate of the point. */
@property (nonatomic, readwrite) CGFloat             y;
/** Pressure of the point. */
@property (nonatomic, readwrite) CGFloat             f;
/** Width of the point. */
@property (nonatomic, readwrite) CGFloat             w;
/** Timestamp of the point. */
@property (nonatomic, readwrite) NSTimeInterval      t;

/**
 * Create a new capture info object.
 *
 * @param x CGFloat X coordinate of the point.
 * @param y CGFloat Y coordinate of the point.
 * @param f CGFloat Pressure of the point.
 * @param w CGFloat Width of the point. 
 * @param timeInterval NSTimeInterval Timestamp of the point.
 */
+ (instancetype)captureInfoWithX:(CGFloat)x andY:(CGFloat)y pressure:(CGFloat)f width:(CGFloat)w timeInterval:(NSTimeInterval)timeInterval;

@end
