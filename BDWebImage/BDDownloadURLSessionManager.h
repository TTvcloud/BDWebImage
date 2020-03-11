#import "BDDownloadManager.h"

@interface BDDownloadURLSessionManager : BDDownloadManager
@property (nonatomic, strong, readonly)NSURLSession *session;
@end
