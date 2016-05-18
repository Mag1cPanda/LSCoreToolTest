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
{
    UITableView *table;
}
@end

@implementation ViewController



- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    table = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
    table.backgroundColor = RGB16Color(777777);
    
    NSLog(@"table.width -> %f",table.width);
    NSLog(@"SCREEN_H -> %f",SCREEN_H);
    NSLog(@"SCREEN_W -> %f",SCREEN_W);
    
    UILabel *lab = [[UILabel alloc] initWithFrame:CGRectMake(100, 100, 200, 50)];
    lab.font = Font(20);
    lab.textColor = [UIColor whiteColor];
    lab.text = @"Test";
    lab.backgroundColor = [UIColor grayColor];
    [self.view addSubview:lab];
    
    if (iOS_7_OR_LATER) {
        NSLog(@">=iOS7");
    }
    
    if (iOS_8_OR_LATER) {
        NSLog(@">=iOS8");
    }
    
    if (iOS_9_OR_LATER) {
        NSLog(@">=iOS9");
    }
    
    if (iPad) {
        NSLog(@"iPad");
    }
    if (iPhone4_OR_4s) {
        NSLog(@"iPhone4_OR_4s");
    }
    if (iPhone5_OR_5c_OR_5s) {
        NSLog(@"iPhone5_OR_5c_OR_5s");
    }
    if (iPhone6_OR_6s) {
        NSLog(@"iPhone6_OR_6s");
    }
    if (iPhone6Plus_OR_6sPlus) {
        NSLog(@"iPhone6Plus_OR_6sPlus");
    }
    
    NSLog(@"%@",CurrentLanguage);
    NSLog(@"%f",CurrentSystemVersion);
    
    WeakSelf(weakSelf);
    NSLog(@"%f",weakSelf.view.width);
    
    UIImage *image = LoadImage(@"imgName", @"imgType");
    NSLog(@"%f",image.size.width);
    
    [LSNotificationCenter postNotificationName:@"SomeNotification" object:nil];
    
    LSApplication.statusBarHidden = YES;
    
    [Util saveNSUserDefaultsForBOOL:YES forKey:@"bool"];
    
    BOOL b = [Util getDataForKey:@"bool"];
    NSLog(@"%d",b);
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
