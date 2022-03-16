// Copyright MyScript. All rights reserved.

#import <UIKit/UIKit.h>

/**
 * Interface CandidateInfo.
 */
@interface IMCandidateInfo : NSObject {
  NSRange       _range;
  NSUInteger    _selectedIndex;
  NSArray       *_labels;
  NSArray       *_completions;
  NSArray       *_sources;
}

/** Character range. */
@property (nonatomic, readonly) NSRange      range;
/** Index of the selected candidate and completion labels. */
@property (nonatomic, readonly) NSInteger    selectedIndex;
/** Array of candidate labels for this character range. */
@property (nonatomic, readonly) NSArray      *labels;
/** Array of completion labels for this character range. */
@property (nonatomic, readonly) NSArray      *completions;
/** Array of LK sources for this character range. */
@property (nonatomic, readonly) NSArray      *sources;

/**
 * Create a new candidate info object.
 *
 * @param range NSRange range of the candidate info.
 * @param selectedIndex NSUInteger index of the selected candidate.
 * @param labels NSArray array of labels.
 * @param completions NSArray array of completions.
 * @param sources NSArray array of sources.
 *
 */
+ (instancetype)candidateInfoWithRange:(NSRange)range selectedIndex:(NSInteger)selectedIndex labels:(NSArray*)labels completions:(NSArray*)completions sources:(NSArray*)sources;

@end
