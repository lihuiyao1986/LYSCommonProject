//
//  JSONTool.h
//  LYSCommonProject
//
//  Created by jk on 2017/3/8.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface JSONTool : NSObject

#pragma mark - 将字典对象转换为 JSON 字符串
+ (NSString *)jsonPrettyStringEncoded:(NSDictionary *)dictionary;

#pragma mark - 将数组对象转换为 JSON 字符串
+ (NSString *)jsonPrettyStringEncodedFromArray:(NSArray *)array;

@end
