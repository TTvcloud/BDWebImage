#import "BDViewController.h"
#import <BDWebImageToB/BDWebImage.h>

@interface BDViewController ()
{
    NSInteger index;
}
//@property (nonatomic, strong) BDImageView *imageView;
@property (nonatomic, strong) UILabel *imageLabel;
@property (nonatomic, strong) BDImageView *demoImageView;
@end

@implementation BDViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor lightGrayColor];
    
    if (self.showType == BDImageShowTypeWebP) {
        [self showWebP];
    }
    else if (self.showType == BDImageShowTypeGIF) {
        [self showGIF];
    }
}

- (void)showWebP {
    NSString *url = @"https://sf6-ttcdn-tos.pstatp.com/img/tos-cn-i-0000/ec654079b09e4b0799df76be74e9907e~1440x810_q80.webp";
    
    [self.demoImageView bd_setImageWithURL:[NSURL URLWithString:url]];
    [self.view addSubview:self.demoImageView];
}

- (void)showGIF {
    NSString *url = @"https://img.wowoqq.com/allimg/180112/1-1P112042I9-50.gif";
    
    [self.demoImageView bd_setImageWithURL:[NSURL URLWithString:url] options:BDImageProgressiveDownload|BDImageNoRetry];
//    [self.demoImageView bd_setImageWithURL:[NSURL URLWithString:url] options:0];
    [self.view addSubview:self.demoImageView];
    
    UIButton *btn1 = [[UIButton alloc] initWithFrame:CGRectMake(10, 100, 200, 50)];
    [btn1 setTitle:@"Start" forState:UIControlStateNormal];
    [btn1 addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];
    btn1.tag = 1001;
    [self.view addSubview:btn1];
    
    UIButton *btn2 = [[UIButton alloc] initWithFrame:CGRectMake(10, 150, 200, 50)];
    [btn2 setTitle:@"Stop" forState:UIControlStateNormal];
    [btn2 addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];
    btn2.tag = 1002;
    [self.view addSubview:btn2];
    
    UITextField *field = [[UITextField alloc] initWithFrame:CGRectMake(10, 200, 200, 50)];
    field.backgroundColor = [UIColor yellowColor];
    field.placeholder = @"Custom loop count";
    field.tag = 1003;
    [self.view addSubview:field];
    [field resignFirstResponder];
}

- (void)btnClick:(UIView *)sender {
    NSInteger tag = sender.tag;
    
    int loopCount = [((UITextField *)[self.view viewWithTag:1003]).text intValue];
    self.demoImageView.customLoop = loopCount;
    
    if (tag == 1001) {
        [self.demoImageView.player startPlay];
    }
    else if (tag == 1002) {
        [self.demoImageView.player stopPlay];
    }
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (UIImageView *)demoImageView {
    if (!_demoImageView) {
        _demoImageView = [BDImageView new];
        _demoImageView.frame = (CGRect){0,0,300,300};
        _demoImageView.center = self.view.center;
    }
    return _demoImageView;
}
@end
