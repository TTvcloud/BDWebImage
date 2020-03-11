#import "BDImageMonitor.h"

@interface BDImageMonitor ()

@property (nonatomic, copy, readwrite) NSString *module;
@property (nonatomic, copy, readwrite) NSString *action;

- (instancetype)initWithModule:(NSString *)module action:(NSString *)action;

@end
