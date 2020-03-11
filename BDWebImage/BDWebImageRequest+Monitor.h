#import "BDWebImageRequest.h"

#define BDImageRequestTimestamp(request,record) [request recorder].record = CACurrentMediaTime() * 1000; 

@interface BDWebImageRequest ()

@property (nonatomic, strong, readwrite) BDImagePerformanceRecoder *recorder;

@end
