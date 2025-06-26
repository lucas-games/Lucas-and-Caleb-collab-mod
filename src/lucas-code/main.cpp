#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(myButton);

		myButton->setID("my-button"_spr);

		menu->updateLayout();

		return true;
	}

	void onMyButton(CCObject*) {
		FLAlertLayer::create(
			"Geode",
			"I have played a sound",
			"OK"
		)->show();

		static int sound = 0;

		if (sound == 0) {
			FMODAudioEngine::sharedEngine()->playEffect("geometry-dash.mp3"_spr);
		} else if (sound == 1) {
			FMODAudioEngine::sharedEngine()->playEffect("magicExplosion.ogg"_spr);
		} else if (sound == 2) {
			FMODAudioEngine::sharedEngine()->playEffect("keyboard-typing-sound.mp3"_spr);
		} else if (sound == 3) {
			FMODAudioEngine::sharedEngine()->playEffect("vine-boom.mp3"_spr);
		}

		sound = sound + 1;

		if (sound >= 4) {
			sound = 1;
		}
	}
};