//
//  FileTools.h
//  LYSCommonProject
//
//  Created by jk on 2017/3/8.
//  Copyright © 2017年 Goldcard. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FileTools : NSObject

#pragma mark - 获取磁盘总空间
+ (CGFloat)diskOfAllSizeMBytes;

#pragma mark - 磁盘可用空间
+ (CGFloat)diskOfFreeSizeMBytes;

#pragma mark - 获取文件大小
+ (long long)fileSizeAtPath:(NSString *)filePath;

#pragma mark - 获取文件夹下所有文件的大小
+ (long long)folderSizeAtPath:(NSString *)folderPath;


@end
