//
//  MBRecognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 21/11/2017.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MBMicroblinkDefines.h"
#import "MBEntity.h"
#import "MBRecognizerResult.h"

#if MB_RESULT_JSONIZATION
@class MBSignedPayload;
#endif

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all recognizers
 */
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBRecognizer : MBEntity

/**
 * Base recognizer result.
 */
@property (nonatomic, readonly, weak) MBRecognizerResult *baseResult;

- (UIInterfaceOrientationMask)getOptimalHudOrientation;

#if MB_RESULT_JSONIZATION
/**
 * Returns the signed JSON representation of this entity's current state as a MBSignedPayload.
 *
 * @return signed JSON representation of this entity's current state.
 */
- (MBSignedPayload *)toSignedJson;
#endif

@end

NS_ASSUME_NONNULL_END
