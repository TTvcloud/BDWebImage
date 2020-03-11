#import "BDWebImageManager.h"


@interface BDWebImageManager (Private)
- (void)_cancelRequest:(BDWebImageRequest *)request;
- (NSString *)requestKeyWithURL:(NSURL *)url;
@end
