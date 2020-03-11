#import "BDDownloadTask.h"

@interface BDDownloadTask (Private)

@property (nonatomic, assign, readwrite) int64_t expectedSize;
@property (nonatomic, assign, readwrite) int64_t receivedSize;

- (void)_cancel;
- (void)_setReceivedSize:(int64_t)receivedSize expectedSize:(int64_t)expectedSize;
- (void)setFinished:(BOOL)finished;

@end
