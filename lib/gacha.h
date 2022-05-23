#ifndef GIWSCLI_H
#define GIWSCLI_H 1
#include <cstddef>
#include <assert.h>
#include <map>
#include <array>

#include "cn_item.h"
#include "en_item.h"
#include "random_gen.h"
#define MAX_ITEMS 118
#define MAX_WEIGHT 10000
#define UP_SSR_CHARACTER_COUNT 1
#define UP_SR_CHARACTER_COUNT 3
#define UP_SSR_WEAPON_COUNT 2
#define UP_SR_WEAPON_COUNT 5
#define CHARACTEREVENT_SSR_CHARACTER_WEIGHT 60
#define CHARACTEREVENT_SR_CHARACTER_WEIGHT 510
#define CHARACTEREVENT_R_WEAPON_WEIGHT 9430
#define CHARACTEREVENT_SSR_RADIO 600
#define CHARACTEREVENT_SR_RADIO 5100
#define CHARACTEREVENT_SSR_GUARANTEE 73
#define CHARACTEREVENT_SR_GUARANTEE 8
#define CHARACTEREVENT_SR_PLACIDITY 16
#define CHARACTEREVENT_SR_PLACIDITY_WEIGHT 255
#define CHARACTEREVENT_SR_PLACIDITY_RADIO 2550

#define WEAPONEVENT_SSR_CHARACTER_WEIGHT 70
#define WEAPONEVENT_SR_CHARACTER_WEIGHT 600
#define WEAPONEVENT_R_WEAPON_WEIGHT 9330
#define WEAPONEVENT_SSR_RADIO_NORMAL 700
#define WEAPONEVENT_SSR_RADIO_ADVANCED 350
#define WEAPONEVENT_SR_RADIO_NORMAL 6600
#define WEAPONEVENT_SR_RADIO_ADVANCED 3000
#define WEAPONEVENT_SSR_GUARANTEE_NORMAL 62
#define WEAPONEVENT_SSR_GUARANTEE_ADVANCED 73
#define WEAPONEVENT_SR_GUARANTEE 8


namespace gacha {
enum class BannerType {
    Character_Event_Wish,
    Character_Event_Wish_2,
    Weapon_Event_Wish,
    Standard_Wish,
    Beginner_Wish,
};

enum class Rarity {
    Rare_Weapon,
    Super_Rare_Weapon,
    Superior_Super_Rare_Weapon,
    Super_Rare_Character,
    Superior_Super_Rare_Characeter,
};

enum class FateWeapon {
    Weapon_1,
    Weapon_2,
    Weapon_None,
};

enum class CharacterEventType {
    CharacterEvent_1,
    CharacterEvent_2,
    CharacterEvent_Unknown,
};

class GlobalDataManager {
public:
    static const std::array<int, 5> standard_ssr_character;  //  常驻五星人物
    static const std::array<int, 10> standard_ssr_weapon;  //  常驻五星武器
    static const std::array<int, 18> standard_sr_weapon;  //  常驻四星武器
    static const std::array<int, 13> rare_weapon;  //  三星武器
    static const std::array<int, 11> all_sr_character_activity_1;
    static const std::array<int, 13> all_sr_character_activity_2;
    static const std::array<int, 14> all_sr_character_activity_3;
    static const std::array<int, 15> all_sr_character_activity_4;
    static const std::array<int, 16> all_sr_character_activity_5;
    static const std::array<int, 17> all_sr_character_activity_6;
    static const std::array<int, 18> all_sr_character_activity_7;
    static const std::array<int, 19> all_sr_character_activity_8;
    static const std::array<int, 20> all_sr_character_activity_9;

    static const int tempga1[30][3], tempga2[30][3], tempga3[30],
        tempgb1[6][3], tempgb2[6][3], tempgb3[6], tempgc1[29][2], tempgc2[29][5],
        tempgc3[29][5], tempgc4[29][2], nup_four_cg31[14], nup_four_cg32[16],
        nup_four_cg33[17], nup_four_cg34[18], nup_four_cg35[19], nup_four_cg36[20],
        nup_four_cg37[21], nup_four_cg38[22], nup_four_cg39[23];
    static const int tempga4[9], tempgb4[6];

    static void InitCharacterActivitysInfomationMap();
    static void InitCharacterActivitysInfomationMapEvent2();
    static void InitWeaponActivitysInfomationMap();

    static bool GetCharacterActivitysInfomationByEvent(const int& event, const int*& activitys, size_t& activitys_size);
    static bool GetCharacterActivitysInfomationByEvent2(const int& event, const int*& activitys, size_t& activitys_size);
    static bool GetWeaponActivitysInfomationByEvent(const int& event, const int*& activitys, size_t& activitys_size);

    static std::map<int, std::pair<const int*, size_t>> m_character_event_activitys_size_map;
    static std::map<int, std::pair<const int*, size_t>> m_character_event2_activitys_size_map;
    static std::map<int, std::pair<const int*, size_t>> m_weapon_event_activitys_size_map;
};

class GachaHelper {
public:
    GachaHelper();
    virtual void GachaGacha() = 0;
    Rarity GetRarity() { return m_current_rarity; };
    int GetItemId() { return m_item_id; };
protected:
    virtual void InitHelper() = 0;
    virtual void PoolStair(int chosen_event = -1) = 0;
    virtual void SetPool(const int index, const size_t item_count,
        const int* nup_four_cgm) = 0;
    void ini_ams(int* in, size_t ins, const int* out);

    void pool_stair_4(int64_t chosen_banner_p);

    //  随机返回入参中的一个成员
    int ResultPick(const int* kindx, size_t sizekind);

    //  加权随机采样
    Rarity WRSpick(const std::vector <int>& weight, bool is_character);

    void core_f_3();
    void core_f_4();
    void core_f_5();
    void post_add();
    void GachaInit();

    bool is_noelle;
    bool m_is_ssr_guarantee;  //  标记下一次五星是否是大保底
    bool m_is_sr_guarantee;  //  标记下一次四星是否是大保底
    int m_item_id, m_current_item_kind_symbol,
        //  TODO 后面移除
        up_item_id,
        //  TODO 这个count没什么用，后面换个实现方式
        countx;
    int m_sr_assurance_number;  //  此前多少抽没有抽到四星
    int m_ssr_assurance_number;  //  此前多少抽没有抽到五星
    int m_sr_character_counter;  //  平稳机制，记录已经连续多少抽是四星角色
    int m_sr_weapon_counter;  //  平稳机制，记录已经连续多少抽是四星武器

    Rarity m_current_rarity;
    std::vector<int> m_all_four_star_character;  //  当期所有四星角色，包括up角色
    //  TODO 用于校验是否需要重置保底，后面改个名
    std::vector<int> five_check;
    std::vector<int> four_check;

    std::vector<int> m_probability_increased_ssr;  //  当期UP五星
    std::vector<int> m_probability_increased_sr;  //  当期UP四星
    //  TODO 只有标配池子用
    int unmet5_w;
    int unmet5_c;
};

class CharacterGachaHelper : public GachaHelper {
public:
    CharacterGachaHelper() : m_event_type(CharacterEventType::CharacterEvent_Unknown) {
        InitHelper();
    }
    void SetEventType(const CharacterEventType& event_type);
    void SetBanner(int chosen_event = -1);
    virtual void GachaGacha();
    
protected:
    virtual void InitHelper();
    virtual void PoolStair(int chosen_event = -1);
    virtual void SetPool(const int index, const size_t item_count,
        const int* items);
    //  角色祈愿
    void CharacterEventWish();

private:
    CharacterEventType m_event_type;
};

class WeaponGachaHelper : public GachaHelper {
public:
    WeaponGachaHelper() : m_fate_weapon(FateWeapon::Weapon_None), fate_points(0) {
        InitHelper();
    }
    virtual void GachaGacha();
    void SetBanner(int chosen_event = -1);
    bool SetFateWeapon(const FateWeapon& fate_weapon);

protected:
    virtual void InitHelper();
    virtual void PoolStair(int chosen_event = -1);
    virtual void SetPool(const int index, const size_t item_count,
        const int* items);
    void WeaponEventWish();

private:
    FateWeapon m_fate_weapon;
    int fate_points;
};

class StandardGachaHelper : public GachaHelper {
public:
    virtual void GachaGacha() {};

protected:
    virtual void InitHelper() {};
    virtual void PoolStair(int chosen_event = -1) {};
    virtual void SetPool(const int index, const size_t item_count,
        const int* items) {};
};

class BeginnerGachaHelper : public GachaHelper {
public:
    virtual void GachaGacha() {};

protected:
    virtual void InitHelper() {};
    virtual void PoolStair(int chosen_event = -1) {};
    virtual void SetPool(const int index, const size_t item_count,
        const int* items) {};
};

class GachaHelperFactory {
public:   
    ~GachaHelperFactory() {
        for (auto& helper : m_helpers) {
            delete helper.second;
        }
    }
    gacha::GachaHelper* GetHelper(const BannerType& chosen_banner);
private:
    std::map<BannerType, GachaHelper*> m_helpers;
};

#if CN_ITEM_H
extern const char *s_pname_cn[128], *s_pnameshort_cn[128], *s_pdetails_cn[128];
#endif
#if EN_ITEM_H
extern const char *s_pname_en[128], *s_pnameshort_en[128], *s_pdetails_en[128];
#endif
}  // namespace gacha
#endif
