#import <Foundation/Foundation.h>

@class BDImageMonitor;
NS_ASSUME_NONNULL_BEGIN
@interface BDImageMonitorManager : NSObject

/**
 返回指定模块和指定监控指标的监控器

 @param module 指定模块，如果传空则默认为__all__
 @param action 指定监控指标，如果传空则默认为default
 @return 监控器
 */

+ (BDImageMonitor *)monitorForModule:(NSString *)module action:(NSString *)action;

/**
 *  上报
 *
 *  @param data 上报的字典信息
 *  @param logType   日志类型
 */
+ (void)trackData:(NSDictionary *)data logTypeStr:(NSString *)logType;

/**
 *  上报
 *
 *  @param serviceName  serviceName
 *  @param status       是一个float类型的，不可枚举
 *  @param extraValue  额外信息，方便追查问题使用
 */
+ (void)trackService:(NSString *)serviceName status:(NSInteger)status extra:(NSDictionary *)extraValue;

+ (void)endSDWebImageReqAndReport:(nullable NSURL *)url monitor:(BDImageMonitor *)monitor;
NS_ASSUME_NONNULL_END
@end
