//
//  GCDQueueUtil.h
//  GisHelper
//
//  Created by jk on 2017/4/16.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GCDQueueUtil : NSObject

#pragma mark - 在主线程执行任务
+(void)runInMain:(void(^)())task asyn:(BOOL)asyn;

#pragma mark - 在global的执行任务
+(void)runInGlobal:(void(^)())task asyn:(BOOL)asyn;

#pragma mark - 延迟执行
+(void)delay:(NSTimeInterval)delay task:(void(^)())task isMain:(BOOL)isMain;

@end
