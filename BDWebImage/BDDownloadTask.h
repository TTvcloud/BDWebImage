//
//  BDDownloadTask.h
//  BDWebImage
//
//  Created by 刘诗彬 on 2017/11/28.
//

#import <Foundation/Foundation.h>

@class BDDownloadTask;

typedef NS_ENUM(NSUInteger, BDDownloadTaskOptions)
{
    BDDownloadTaskDefaultOption = 0,
    BDDownloadTaskLowPriority = 1<<0,
    BDDownloadTaskHighPriority = 1<<1,
};

extern NSString *const kBDDownloadTaskInfoHTTPResponseHeaderKey;
extern NSString *const kBDDownloadTaskInfoHTTPRequestHeaderKey;
extern NSString *const kBDDownloadTaskInfoOriginalURLKey;
extern NSString *const kBDDownloadTaskInfoCurrentURLKey;

@protocol BDDownloadTaskDelegate <NSObject>
- (void)downloadTask:(BDDownloadTask *)task failedWithError:(NSError *)error;
- (void)downloadTask:(BDDownloadTask *)task finishedWithData:(NSData *)data savePath:(NSString *)savePath;
- (void)downloadTaskDidCanceled:(BDDownloadTask *)task;

@optional
- (void)downloadTask:(BDDownloadTask *)task receivedSize:(NSInteger)receivedSize expectedSize:(NSInteger)expectedSize;
- (void)downloadTask:(BDDownloadTask *)dataTask
    didReceiveData:(NSData *)data;
@end

@interface BDDownloadTask : NSOperation
@property (nonatomic, strong, readonly) NSURL *url;
@property (nonatomic, strong) NSURLRequest *request;
@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *defaultHeaders;//http request default headers

@property (nonatomic, assign) BDDownloadTaskOptions options;

@property (nonatomic, strong) NSString *tempPath;//临时文件缓存路径，由DownloadManager管理

@property (nonatomic, assign) BOOL downloadResumeEnabled;//是否支持断点续传
@property (nonatomic, weak) id<BDDownloadTaskDelegate> delegate;
@property (nonatomic, assign) NSTimeInterval timeoutInterval;
@property (nonatomic, assign) NSTimeInterval timeoutIntervalForResource;

@property (nonatomic, assign, readonly) int64_t expectedSize;
@property (nonatomic, assign, readonly) int64_t receivedSize;

@property (nonatomic, assign, readonly) double startTime;
@property (nonatomic, assign, readonly) double finishTime;
@property (nonatomic, assign) BOOL enableLog;


- (instancetype)initWithURL:(NSURL *)url;
@end
