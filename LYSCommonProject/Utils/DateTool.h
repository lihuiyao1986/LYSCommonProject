//
//  DateTool.h
//  LYSCommonProject
//
//  Created by jk on 2017/3/8.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DateTool : NSObject

#pragma mark - 获取当前时间
//format: @"yyyy-MM-dd HH:mm:ss"、@"yyyy年MM月dd日 HH时mm分ss秒"
+ (NSString *)currentDateWithFormat:(NSString *)format;

#pragma mark - 计算上次日期距离现在多久, 如 xx 小时前、xx 分钟前等
+ (NSString *)timeIntervalFromLastTime:(NSString *)lastTime
                        lastTimeFormat:(NSString *)format1
                         ToCurrentTime:(NSString *)currentTime
                     currentTimeFormat:(NSString *)format2;

#pragma mark - 判断手机号码格式是否正确
+ (BOOL)valiMobile:(NSString *)mobile;

#pragma mark - 利用正则表达式验证
+ (BOOL)isAvailableEmail:(NSString *)email;

@end
