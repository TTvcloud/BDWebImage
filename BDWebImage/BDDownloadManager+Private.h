#import "BDDownloadManager.h"

@interface BDDownloadManager (Private)<BDDownloadTaskDelegate>
- (void)_startPendingTaskIfNeed;
- (BDDownloadTask *)_creatTaskWithURL:(NSURL *)url identifier:(NSString *)identifier timeout:(CFTimeInterval)timeout;
@end
