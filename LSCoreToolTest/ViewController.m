//
//  ViewController.m
//  LSCoreToolTest
//
//  Created by Mag1cPanda on 16/4/25.
//  Copyright © 2016年 Mag1cPanda. All rights reserved.
//

#import "ViewController.h"
#import <LSCoreTool/LSCoreTool.h>
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    UIView *view = [UIView newAutoLayoutView];
    view.backgroundColor = RGB16Color(777777);
    [self.view addSubview:view];
    [view autoPinEdgesToSuperviewEdges];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
