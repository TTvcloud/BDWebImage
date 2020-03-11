@import UIKit;

typedef enum : NSUInteger {
    BDImageShowTypeWebP,
    BDImageShowTypeGIF,
} BDImageShowType;

@interface BDViewController : UIViewController
@property (nonatomic, assign) BDImageShowType showType;
@end
