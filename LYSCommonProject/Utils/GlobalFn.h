//-------------------获取设备大小-------------------------
// NavBar高度
#define NavigationBar_HEIGHT 44

// tabBar的高度
#define TabBar_HEIGHT 49.f

// 状态栏的高度
#define StatusBarH [UIApplication sharedApplication].statusBarFrame.size.height

// 状态栏底部y坐标
#define OffsetStateBarHeight    ((DEVICE_OS_VERSION_VALUE >= 7.0)? StateBarHeight : 0.f)


// 屏幕高度
#define ScreenHeight            [[UIScreen mainScreen] bounds].size.height

// 屏幕宽度
#define ScreenWidth             [[UIScreen mainScreen] bounds].size.width

// 屏幕可操作高度
#define MainHeight              ((DEVICE_OS_VERSION_VALUE >= 7.0)? ScreenHeight : (ScreenHeight - StatusBarH))

// 屏幕可操作宽度
#define MainWidth               ScreenWidth

// 6P、6sP
#define IS_iPhone6Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)
// 6、6s
#define IS_iPhone6     ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
// 5、5s
#define IS_iPhone5     ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
// 3g、4、4s
#define IS_iPhone4     ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

// 是否是Retina屏幕
#define IS_Retina      ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? [[UIScreen mainScreen] currentMode].size.width > 320 : NO)

// app版本号
#define DEVICE_APP_VERSION       (NSString *)[[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"]
// app Build版本号
#define DEVICE_APP_BUILD         (NSString *)[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

// 系统版本号（string）
#define DEVICE_OS_VERSION        [[UIDevice currentDevice] systemVersion]
// 系统版本号（float）
#define DEVICE_OS_VERSION_VALUE  [DEVICE_OS_VERSION floatValue]

//-------------------获取设备大小-------------------------


//-------------------打印日志-------------------------
//DEBUG  模式下打印日志,当前行
#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

//重写NSLog,Debug模式下打印日志和当前行数
#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\nfunction:%s line:%d content:%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif


//DEBUG  模式下打印日志,当前行 并弹出一个警告
#ifdef DEBUG
#   define ULog(fmt, ...)  { UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]  delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil]; [alert show]; }
#else
#   define ULog(...)
#endif


//----------------------系统----------------------------

//获取系统版本
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion [[UIDevice currentDevice] systemVersion]

//获取当前语言
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

//判断是否 Retina屏、设备是否%fhone 5、是否是iPad
#define isRetina ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)


//判断是真机还是模拟器
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif


//检查系统版本
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)


//----------------------内存----------------------------

//使用ARC和不使用ARC
#if __has_feature(objc_arc)
//compiling with ARC
#else
// compiling without ARC
#endif

#pragma mark - common functions
#define RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }

//释放一个对象
#define SAFE_DELETE(P) if(P) { [P release], P = nil; }

#define SAFE_RELEASE(x) [x release];x=nil


//----------------------内存----------------------------


//----------------------图片----------------------------

//读取本地图片
#define LOADIMAGE(file,ext) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:ext]]

//定义UIImage对象
#define IMAGE(A) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:A ofType:nil]]

//定义UIImage对象
#define ImageNamed(_pointer) [UIImage imageNamed:[UIUtil imageName:_pointer]]

//建议使用前两种宏定义,性能高于后者
//----------------------图片----------------------------



//----------------------颜色类---------------------------
// rgb颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

// rgb颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue,alpha) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:alpha]

//带有RGBA的颜色设置
#define COLOR(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

// 获取RGB颜色
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define RGB(r,g,b) RGBA(r,g,b,1.0f)

//背景色
#define BACKGROUND_COLOR [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]

//清除背景色
#define CLEARCOLOR [UIColor clearColor]

#pragma mark - color functions
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]

//----------------------颜色类--------------------------



//----------------------其他----------------------------

//方正黑体简体字体定义
#define FONT(F) [UIFont fontWithName:@"FZHTJW--GB1-0" size:F]


//定义一个API
#define APIURL                @"http://xxxxx/"
//登陆API
#define APILogin              [APIURL stringByAppendingString:@"Login"]

//设置View的tag属性
#define VIEWWITHTAG(_OBJECT, _TAG)    [_OBJECT viewWithTag : _TAG]
//程序的本地化,引用国际化的文件
#define MyLocal(x, ...) NSLocalizedString(x, nil)

//G－C－D
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)

//NSUserDefaults 实例化
#define USER_DEFAULT [NSUserDefaults standardUserDefaults]


//由角度获取弧度 有弧度获取角度
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)


/// 常用文件路径
#define PathForDocument NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0]
#define PathForLibrary NSSearchPathForDirectoriesInDomains (NSLibraryDirectory, NSUserDomainMask, YES)[0]
#define PathForCaches NSSearchPathForDirectoriesInDomains (NSCachesDirectory, NSUserDomainMask, YES)[0]
#pragma mark - shared tool
#define SharedUserDefault [NSUserDefaults standardUserDefaults]
#define SharedNotificationCenter [NSNotificationCenter defaultCenter]
#define SharedFileManager [NSFileManager defaultManager]
#define SharedApplicationDelegate [[UIApplication sharedApplication] delegate]



/** 全局线程执行方法 */
static inline void st_dispatch_async_global(dispatch_block_t block) {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block);
}
/** 主线程执行方法 */
static inline void st_dispatch_async_main(dispatch_block_t block) {
    dispatch_async(dispatch_get_main_queue(), block);
}
/** 主线程延时执行方法 */
static inline void st_dispatch_async_main_after(NSTimeInterval ti, dispatch_block_t block) {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(ti * NSEC_PER_SEC)), dispatch_get_main_queue(), block);
}


/** data format */
#define NSStringFromNumber_c( __v__ ) [NSString stringWithFormat:@"%@", @(__v__)]
#define NSStringFromObject_oc( __v__ ) [NSString stringWithFormat:@"%@", __v__]

// weak self
#define WeakSelf __weak typeof(self) weakSelf = self;

// 版本号
#define appVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]


#define APPLICATION   [UIApplication sharedApplication]
#define APPDLE        (AppDelegate*)[APPLICATION delegate]


/***frame 相关**/
#define FRAME_ORIGIN(aFrame)              ((aFrame).origin)
#define FRAME_X(aFrame)                   ((aFrame).origin.x)
#define FRAME_Y(aFrame)                   ((aFrame).origin.y)

#define FRAME_SIZE(aFrame)                ((aFrame).size)
#define FRAME_HEIGHT(aFrame)              ((aFrame).size.height)
#define FRAME_WIDTH(aFrame)               ((aFrame).size.width)

/*修改frame对象的x、y、width、height属性值*/
#define FRAME_CHANGE_X(aFrame,x)          CGRectMake(x, (aFrame).origin.y, (aFrame).size.width, (aFrame).size.height)
#define FRAME_CHANGE_Y(aFrame,y)          CGRectMake((aFrame).origin.x, y, (aFrame).size.width, (aFrame).size.height)
#define FRAME_CHANGE_WIDTH(aFrame,w)      CGRectMake((aFrame).origin.x, (aFrame).origin.y, w, (aFrame).size.height)
#define FRAME_CHANGE_HEIGHT(aFrame,h)     CGRectMake((aFrame).origin.x, (aFrame).origin.y, (aFrame).size.width, h)

// 向左移动offset位移后得到frame对象
#define FRAME_MOVE_Left(aFrame,offset)    CGRectMake((aFrame).origin.x-(offset), (aFrame).origin.y, (aFrame).size.width, (aFrame).size.height)
// 向右移动offset位移后得到frame对象
#define FRAME_MOVE_Right(aFrame,offset)   CGRectMake((aFrame).origin.x+(offset), (aFrame).origin.y, (aFrame).size.width, (aFrame).size.height)
// 向上移动offset位移后得到frame对象
#define FRAME_MOVE_Up(aFrame,offset)      CGRectMake((aFrame).origin.x, (aFrame).origin.y-(offset), (aFrame).size.width, (aFrame).size.height)
// 向下移动offset位移后得到frame对象
#define FRAME_MOVE_Down(aFrame,offset)    CGRectMake((aFrame).origin.x, (aFrame).origin.y+(offset), (aFrame).size.width, (aFrame).size.height)

#define VIEW_X_Right(aView)      ((aView).frame.origin.x + (aView).frame.size.width)  // 视图右边界x坐标
#define VIEW_Y_Bottom(aView)     ((aView).frame.origin.y + (aView).frame.size.height) // 视图底部y坐标

//Center相关
#define VIEW_CENTER(aView)       ((aView).center)
#define VIEW_CENTER_X(aView)     ((aView).center.x)
#define VIEW_CENTER_Y(aView)     ((aView).center.y)

//字体相关
#define FONT_SIZE(f)            [UIFont systemFontOfSize:(f)]
#define FONT_BOLD_SIZE(f)       [UIFont boldSystemFontOfSize:(f)]
#define FONT_ITALIC_SIZE(f)     [UIFont italicSystemFontOfSize:(f)]
#define IS_SmallScreen (IS_iPhone5 || IS_iPhone4)

#define MaxFontSize    (IS_SmallScreen ? 21.f : 25.f )
#define LagerFontSize  (IS_SmallScreen ? 17.f : 19.f )
#define BigFontSize    (IS_SmallScreen ? 15.f : 17.f )
#define NormalFontSize (IS_SmallScreen ? 13.f : 15.f )
#define SmallFontSize  (IS_SmallScreen ? 11.f : 13.f )
#define MinFontSize    (IS_SmallScreen ? 9.f  : 11.f )


//颜色相关
#define COLOR_Clear           [UIColor clearColor]
#define COLOR_White           [UIColor whiteColor]
#define COLOR_Black           [UIColor blackColor]
#define COLOR_Red             [UIColor redColor]
#define COLOR_DarkGray        [UIColor darkGrayColor]
#define COLOR_LightGray       [UIColor lightGrayColor]
#define COLOR_GrayColor       [UIColor grayColor]
#define COLOR_Green           [UIColor greenColor]
#define COLOR_BlueColor       [UIColor blueColor]
#define COLOR_Cyan            [UIColor cyanColor]
#define COLOR_Yellow          [UIColor yellowColor]
#define COLOR_Magenta         [UIColor magentaColor]
#define COLOR_Orange          [UIColor orangeColor]
#define COLOR_Purple          [UIColor purpleColor]
#define COLOR_Brown           [UIColor brownColor]

// 字符串相关
#define StrOfInterger(interger)  [NSString stringWithFormat:@"%ld",(long)(interger)]
#define StrOfFloat(float)        [NSString stringWithFormat:@"%f",(float)]

// Image相关
#define IMG_Name(imgName)        [UIImage imageNamed:(imgName)]
#define IMG_ImgWidth(img)        ((img).size.width)
#define IMG_ImgHeight(img)       ((img).size.height)


// 校验相关
#define STRINGHASVALUE(str)  (str && [str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]].length > 0)
#define IsCanUseString(str)     ((str != nil) && ![str isKindOfClass:[NSNull class]] && [str isKindOfClass:[NSString class]] && [str length] > 0 )
#define IsCanUseArray(arr)      ( arr && (arr != nil) && ![arr isKindOfClass:[NSNull class]] )
#define IsCanUseDic(dic)        ( dic && (dic != nil) && ![dic isKindOfClass:[NSNull class]] )
#define IsCanUseObj(obj)        ( obj && (obj != nil) && ![obj isKindOfClass:[NSNull class]] )
#define IsNullClass(class)      [class isKindOfClass:[NSNull class]]


