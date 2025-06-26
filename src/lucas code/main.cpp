#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		log::debug("Hello from my MenuLayer::init hook! This layer has {} children.", this->getChildrenCount());

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
			"OK", "Cool"
		)->show();

		int sound = 1;

		if (sound == 1) {
			FMODAudioEngine::sharedEngine()->playEffect("geometry-Dash.mp3"_spr);
		} else {
			if (sound == 2) {
				FMODAudioEngine::sharedEngine()->playEffect("magicExplosion.ogg"_spr);
			} else {
				if (sound == 3) {
					FMODAudioEngine::sharedEngine()->playEffect("")
				}
			}
		}

		sound = sound + 1;
	}
};