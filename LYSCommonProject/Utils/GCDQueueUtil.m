//
//  GCDQueueUtil.m
//  GisHelper
//
//  Created by jk on 2017/4/16.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import "GCDQueueUtil.h"

@implementation GCDQueueUtil

#pragma mark - 在主线程执行任务
+(void)runInMain:(void(^)())task asyn:(BOOL)asyn{
    if (asyn){
        dispatch_async(dispatch_get_main_queue(), task);
    }else{
        dispatch_sync(dispatch_get_main_queue(), task);
    }
}

#pragma mark - 在global的执行任务
+(void)runInGlobal:(void(^)())task asyn:(BOOL)asyn{
    if (asyn) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), task);
    }else{
        dispatch_sync(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), task);
    }
}

#pragma mark - 延迟执行
+(void)delay:(NSTimeInterval)delay task:(void(^)())task isMain:(BOOL)isMain{
    dispatch_time_t delayTime = dispatch_time(DISPATCH_TIME_NOW, delay * NSEC_PER_SEC);
    if (isMain) {
        dispatch_after(delayTime, dispatch_get_main_queue(), task);
    }else{
        dispatch_after(delayTime, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), task);
    }
}
@end
