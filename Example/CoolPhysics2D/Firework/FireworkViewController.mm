#import "FireworkViewController.h"
#import "FireworkView.h"

@implementation FireworkViewController

- (void)viewDidLoad {
    _gameView=[[FireworkView alloc] initWithFrame:self.view.frame];
    _updateInterval=0.01;
    [super viewDidLoad];
}

-(void)viewWillAppear:(BOOL)animated
{
    UITapGestureRecognizer* recognizer=[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapAction:)];
    [_gameView addGestureRecognizer:recognizer];
}

-(void)tapAction:(UITapGestureRecognizer*)recognizer;
{
    [(FireworkView*)_gameView fire:recognizer];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end