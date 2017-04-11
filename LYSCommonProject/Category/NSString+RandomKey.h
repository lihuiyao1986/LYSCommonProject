//
//  NSString+RandomKey.h
//  LYSCommonProject
//
//  Created by jk on 2017/4/11.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (MD5)

- (NSString *)MD5;

@end

@interface NSString (MD5)

- (NSString *)MD5;

@end

@interface NSString (RandomKey)

/**
 *  产生一个随机Key，长度为32.
 */
+ (NSString *)randomKey;

@end


@interface NSData (RandomData)
/**
 *  产生随机数据.
 *  @param length 随机数据的长度
 *
 */
+ (NSData *)randomDataWithLength:(NSUInteger)length;

@end
