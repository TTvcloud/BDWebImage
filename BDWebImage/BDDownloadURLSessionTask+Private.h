#import "BDDownloadURLSessionTask.h"
#import "BDDownloadURLSessionManager.h"

@interface BDDownloadURLSessionTask ()<NSURLSessionDownloadDelegate,NSURLSessionDataDelegate>
@property (nonatomic, strong) NSURLSessionTask *task;
@property (nonatomic, weak) BDDownloadURLSessionManager *sessionManager;

@property (nonatomic, strong, readwrite) NSNumber *DNSDuration;/** DNS耗时 单位ms */
@property (nonatomic, strong, readwrite) NSNumber *connetDuration;/** 建立连接耗时 单位ms */
@property (nonatomic, strong, readwrite) NSNumber *sslDuration;/** SSL建连耗时 单位ms */
@property (nonatomic, strong, readwrite) NSNumber *sendDuration;/** 发送耗时 单位ms */
@property (nonatomic, strong, readwrite) NSNumber *waitDuration;/** 等待耗时 单位ms */
@property (nonatomic, strong, readwrite) NSNumber *receiveDuration;/** 接收耗时 单位ms */
@property (nonatomic, strong, readwrite) NSNumber *isSocketReused;
@property (nonatomic, strong, readwrite) NSNumber *isFromProxy;
@property (nonatomic, strong, readwrite) NSString *mimeType;/** 图片类型*/
@property (nonatomic, assign, readwrite) NSInteger statusCode;/** http请求状态码*/
@property (nonatomic, strong, readwrite) NSString *nwSessionTrace;/*图片系统在response header中增加的追踪信息，目前包含回复时间戳和处理总延迟*/

@end
