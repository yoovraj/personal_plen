//
//  ApiClient.m
//  MotorConfiguration_OBJC
//
//  Created by yoovraj shinde on 2017/10/01.
//  Copyright © 2017 ___YOOVRAJSHINDE___. All rights reserved.
//

#import "ApiClient.h"

@implementation ApiClient

+ (instancetype)sharedInstance {
    static ApiClient *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[ApiClient alloc] init];
    });
    return sharedInstance;
    
}

- (void)moveMotor:(NSString *)motorId withAngle:(NSInteger)angle {
    NSString *urlString = [@"http://yoovrajs-macbook-pro.local:5000/motor/"
                           stringByAppendingString:[NSString stringWithFormat:@"%@/%ld", motorId, (long)angle]];
    
    NSURL *url = [NSURL URLWithString:urlString];
    NSURLSessionConfiguration *config = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:config];
    
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:url];
    request.HTTPMethod = @"GET";
    
    NSURLSessionDataTask *datatask = [session dataTaskWithRequest:request
                                                completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error)
    {
        NSLog(@"Success response = %@", response);
        NSLog(@"ERROR = %@", error);
    }];
    [datatask resume];
}

- (void)closeConnections {
    NSString *urlString = @"http://yoovrajs-macbook-pro.local/motor/close";
    
    NSURL *url = [NSURL URLWithString:urlString];
    NSURLSessionConfiguration *config = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:config];
    
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:url];
    request.HTTPMethod = @"GET";
    
    NSURLSessionDataTask *datatask = [session dataTaskWithRequest:request
                                                completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error)
                                      {
                                          NSLog(@"Success response = %@", response);
                                          NSLog(@"ERROR = %@", error);
                                      }];
    [datatask resume];
    
}


@end
