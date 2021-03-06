//
//  IASKAppSettingsViewController.h
//  http://www.inappsettingskit.com
//
//  Copyright (c) 2009:
//  Luc Vandal, Edovia Inc., http://www.edovia.com
//  Ortwin Gentz, FutureTap GmbH, http://www.futuretap.com
//  All rights reserved.
// 
//  It is appreciated but not required that you give credit to Luc Vandal and Ortwin Gentz, 
//  as the original authors of this code. You can give credit in a blog post, a tweet or on 
//  a info page of your app. Also, the original authors appreciate letting them know if you use this code.
//
//  This code is licensed under the BSD license that is available at: http://www.opensource.org/licenses/bsd-license.php
//

// Slightly modified by Jonathan Hersh

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>

#import "IASKSettingsStore.h"

@class IASKSettingsReader;
@class IASKAppSettingsViewController;
@class IASKSpecifier;

@protocol IASKSettingsDelegate
- (void)settingsViewControllerDidEnd:(IASKAppSettingsViewController*)sender;
@optional
- (CGFloat)tableView:(UITableView *)tableView heightForHeaderForKey:(NSString*)key;
- (UIView *)tableView:(UITableView *)tableView viewForHeaderForKey:(NSString*)key;

- (CGFloat)tableView:(UITableView*)tableView heightForSpecifier:(IASKSpecifier*)specifier;
- (UITableViewCell*)tableView:(UITableView*)tableView cellForSpecifier:(IASKSpecifier*)specifier;

- (NSString*)mailComposeBody;
- (UIViewController<MFMailComposeViewControllerDelegate>*)viewControllerForMailComposeView;

- (void)settingsViewController:(IASKAppSettingsViewController*)sender buttonTappedForKey:(NSString*)key;
@end


@interface IASKAppSettingsViewController : UIViewController <UITextFieldDelegate, UINavigationControllerDelegate, MFMailComposeViewControllerDelegate> {
	id<IASKSettingsDelegate>  _delegate;
    UITableView    			*_tableView;
    
    NSMutableArray          *_viewList;
    NSIndexPath             *_currentIndexPath;
	NSIndexPath				*_topmostRowBeforeKeyboardWasShown;
	
	IASKSettingsReader		*_settingsReader;
    id<IASKSettingsStore>  _settingsStore;
	NSString				*_file;
	
	id                      _currentFirstResponder;
    
    BOOL                    _showCreditsFooter;
    BOOL                    _showDoneButton;
}

@property (nonatomic, assign) IBOutlet id delegate;
@property (nonatomic, retain) IBOutlet UITableView *tableView;
@property (nonatomic, retain) NSIndexPath   *currentIndexPath;
@property (nonatomic, retain) IASKSettingsReader *settingsReader;
@property (nonatomic, retain) id<IASKSettingsStore> settingsStore;
@property (nonatomic, copy) NSString *file;
@property (nonatomic, retain) id currentFirstResponder;
@property (nonatomic, assign) BOOL showCreditsFooter;
@property (nonatomic, assign) BOOL showDoneButton;

// JH
@property (nonatomic, retain) NSString *extraFooterText;

- (void)synchronizeSettings;
- (IBAction)dismiss:(id)sender;

// subclassing: optionally override these methods to customize appearance and functionality
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSIndexPath *)tableView:(UITableView *)tableView willSelectRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;
- (UIView *)tableView:(UITableView*)tableView viewForHeaderInSection:(NSInteger)section;
@end
