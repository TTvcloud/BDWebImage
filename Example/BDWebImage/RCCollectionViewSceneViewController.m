#import "RCCollectionViewSceneViewController.h"
#import <BDWebImage.h>


static NSString *const RC_ImageURLPrefix = @"https://qzonestyle.gtimg.cn/qzone/app/weishi/client/testimage/";
static NSInteger const RC_ImageCount = 4799;

@interface RCCustomCollectionViewCell : UICollectionViewCell

@property (nonatomic, strong) UIImageView *imageView;

@end

@implementation RCCustomCollectionViewCell

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        CGRect r = CGRectMake(0, 0, self.contentView.bounds.size.width, self.contentView.bounds.size.height);
        _imageView  = [[UIImageView alloc] initWithFrame:r];
        [self.contentView addSubview:_imageView];
    }
    return self;
}

@end


@interface RCCollectionViewSceneViewController ()<UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout>

@property (nonatomic, strong) UICollectionView *collectionView;
@property (nonatomic, strong) NSMutableArray<NSString *> *imagesURLArr;

@end

@implementation RCCollectionViewSceneViewController

static NSString * const reuseIdentifier = @"CollectionViewCell";

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor lightGrayColor];
    self.navigationItem.rightBarButtonItem = [UIBarButtonItem.alloc initWithTitle:@"Btn"
                                                                            style:UIBarButtonItemStylePlain
                                                                           target:self
                                                                           action:@selector(clickBtn:)];
    [self setupImageURLs];
    [self setupCollectionView];
}

- (void)clickBtn:(UIButton *)btn {
    
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}

- (void)setupCollectionView {
    UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
    CGFloat width = self.view.bounds.size.width/4;
    layout.itemSize =CGSizeMake(width, width);
    layout.minimumLineSpacing = 1;
    layout.minimumInteritemSpacing = 0;
    layout.sectionInset = UIEdgeInsetsMake(0, 0, 0, 0);
    
    CGRect frame = CGRectMake(0, 64, self.view.bounds.size.width, self.view.bounds.size.height-64);
    self.collectionView = [[UICollectionView alloc] initWithFrame:frame collectionViewLayout:layout];
    [self.view addSubview:self.collectionView];
    self.collectionView.backgroundColor = [UIColor clearColor];
    [self.collectionView registerClass:[RCCustomCollectionViewCell class] forCellWithReuseIdentifier:reuseIdentifier];
    
    self.collectionView.delegate = self;
    self.collectionView.dataSource = self;
}

- (void)setupImageURLs {
    self.imagesURLArr = [@[] mutableCopy];
    long size = 1024;//64, 256, 0
    NSString *sizeStr = size > 0 ? [@(size) stringValue] : @"origin";
    for (int i=1; i<=RC_ImageCount; i++) {//http://qzonestyle.gtimg.cn/qzone/app/weishi/client/testimage/1024/4799.jpg
        NSString *imageURL = [NSString stringWithFormat:@"%@%@/%ld.jpg", RC_ImageURLPrefix, sizeStr, (long)i];
        [self.imagesURLArr addObject:imageURL];
    }
}

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return self.imagesURLArr.count;
}

- (RCCustomCollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    RCCustomCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:reuseIdentifier forIndexPath:indexPath];
    cell.backgroundColor = [UIColor lightGrayColor];
    NSURL *url = [NSURL URLWithString:self.imagesURLArr[indexPath.row]];
    [cell.imageView bd_setImageWithURL:url];
    return cell;
}

@end
