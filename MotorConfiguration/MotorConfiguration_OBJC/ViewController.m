//
//  ViewController.m
//  MotorConfiguration_OBJC
//
//  Created by yoovraj shinde on 2017/10/01.
//  Copyright © 2017 ___YOOVRAJSHINDE___. All rights reserved.
//

#import "ViewController.h"
#import "ApiClient.h"

@interface ViewController ()
@property (strong, nonatomic) IBOutlet UILabel *label0;
@property (strong, nonatomic) IBOutlet UISlider *slider0;
@property (strong, nonatomic) IBOutlet UILabel *label1;
@property (strong, nonatomic) IBOutlet UISlider *slider1;
@property (strong, nonatomic) IBOutlet UILabel *label2;
@property (strong, nonatomic) IBOutlet UISlider *slider2;
@property (strong, nonatomic) IBOutlet UILabel *label3;
@property (strong, nonatomic) IBOutlet UISlider *slider3;
@property (strong, nonatomic) IBOutlet UILabel *currentValue;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.label0.text = @"left_shoulder_pitch";
    self.label1.text = @"left_shoulder_roll";
    self.label2.text = @"right_shoulder_pitch";
    self.label3.text = @"right_shoulder_roll";
    
    [self.slider0 addTarget:self
                     action:@selector(sliderValueChanged:)
           forControlEvents:UIControlEventValueChanged];
    self.slider0.minimumValue = 0;
    self.slider0.maximumValue = 180;
    self.slider0.value = 90;
    self.slider0.continuous = NO;
    
    [self.slider1 addTarget:self
                     action:@selector(sliderValueChanged:)
           forControlEvents:UIControlEventValueChanged];
    self.slider1.minimumValue = 0;
    self.slider1.maximumValue = 180;
    self.slider1.value = 90;
    self.slider1.continuous = NO;

    [self.slider2 addTarget:self
                     action:@selector(sliderValueChanged:)
           forControlEvents:UIControlEventValueChanged];
    self.slider2.minimumValue = 0;
    self.slider2.maximumValue = 180;
    self.slider2.value = 90;
    self.slider2.continuous = NO;

    [self.slider3 addTarget:self
                     action:@selector(sliderValueChanged:)
           forControlEvents:UIControlEventValueChanged];
    self.slider3.minimumValue = 0;
    self.slider3.maximumValue = 180;
    self.slider3.value = 90;
    self.slider3.continuous = NO;
    
    self.currentValue.text = @"90";
}

- (void)sliderValueChanged:(UISlider *)sender {
    int angle = (int)sender.value;
    self.currentValue.text = [NSString stringWithFormat:@"%d", angle];
    if (sender == self.slider0) {
        NSLog(@"left_shoulder_pitch (00) angle = %d", angle);
        [ApiClient.sharedInstance moveMotor:@"00" withAngle:angle];
    } else if (sender == self.slider1) {
        NSLog(@"left_shoulder_roll (01) angle = %d", angle);
        [ApiClient.sharedInstance moveMotor:@"01" withAngle:angle];
    } else if (sender == self.slider2) {
        NSLog(@"right_shoulder_roll (02) angle = %d", 180 - angle);
        [ApiClient.sharedInstance moveMotor:@"02" withAngle:180 - angle];
    } else if (sender == self.slider3) {
        NSLog(@"right_shoulder_roll (03) angle = %d", 180 - angle);
        [ApiClient.sharedInstance moveMotor:@"03" withAngle:180 - angle];
    }
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
