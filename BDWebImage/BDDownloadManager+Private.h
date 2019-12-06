//
//  BDDownloadManager+Private.h
//  BDWebImage
//
//  Created by 刘诗彬 on 2017/12/4.
//

#import "BDDownloadManager.h"

@interface BDDownloadManager (Private)<BDDownloadTaskDelegate>
- (void)_startPendingTaskIfNeed;
- (BDDownloadTask *)_creatTaskWithURL:(NSURL *)url identifier:(NSString *)identifier timeout:(CFTimeInterval)timeout;
@end
