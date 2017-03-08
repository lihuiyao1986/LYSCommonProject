//
//  StringTool.h
//  LYSCommonProject
//
//  Created by jk on 2017/3/8.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface StringTool : NSObject

#pragma mark - 获取字符串(或汉字)首字母
+ (NSString *)firstCharacterWithString:(NSString *)string;

#pragma mark - 将字符串数组按照元素首字母顺序进行排序分组
+ (NSDictionary *)dictionaryOrderByCharacterWithOriginalArray:(NSArray *)array;

#pragma mark - 判断字符串中是否含有空格
+ (BOOL)isHaveSpaceInString:(NSString *)string;

#pragma mark - 判断字符串中是否含有某个字符串
+ (BOOL)isHaveString:(NSString *)string1 InString:(NSString *)string2;

#pragma mark - 判断字符串中是否含有中文
+ (BOOL)isHaveChineseInString:(NSString *)string;

#pragma mark - 判断字符串是否全部为数字
+ (BOOL)isAllNum:(NSString *)string;

@end
