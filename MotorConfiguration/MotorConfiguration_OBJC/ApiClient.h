//
//  ApiClient.h
//  MotorConfiguration_OBJC
//
//  Created by yoovraj shinde on 2017/10/01.
//  Copyright © 2017 ___YOOVRAJSHINDE___. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ApiClient : NSObject

+ (instancetype)sharedInstance;

- (void)moveMotor:(NSString *)motorId withAngle:(NSInteger)angle;

- (void)closeConnections;

@end
