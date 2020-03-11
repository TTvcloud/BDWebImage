#import "BDWebImageRequest.h"

@interface BDWebImageRequest (Progress)
- (void)_setReceivedSize:(int64_t)receivedSize andExpectedSize:(int64_t)expectedSize;

- (void)_receiveProgressData:(NSData *)currentReceiveData;

@end
