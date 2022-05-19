#ifndef GIWSCLI_H
#define GIWSCLI_H 1
#include <cstddef>
#include <map>

#include "cn_item.h"
#include "en_item.h"
#include "random_gen.h"
#define MAX_ITEMS 118
#define MAX_WEIGHT 10000
#define UP_SSR_CHARACTER_COUNT 1
#define UP_SR_CHARACTER_COUNT 3

namespace gacha {
    extern const std::array<int, 5> standard_five_star_character;  //  常驻五星人物
    extern const std::array<int, 10> standard_five_star_weapon;  //  常驻五星武器
    extern const std::array<int, 32> standard_four_star_weapon;  //  常驻四星武器
    extern const std::array<int, 13> rare_weapon;  //  三星武器
    extern const std::array<int, 11> nup_four_cg1;
    extern const std::array<int, 13> nup_four_cg2;
    extern const std::array<int, 14> nup_four_cg3;
    extern const std::array<int, 15> nup_four_cg4;
    extern const std::array<int, 16> nup_four_cg5;
    extern const std::array<int, 17> nup_four_cg6;
    extern const std::array<int, 18> nup_four_cg7;
    extern const std::array<int, 19> nup_four_cg8;
    extern const std::array<int, 20> nup_four_cg9;

    extern const int tempga1[30][3], tempga2[30][3], tempga3[30],
        tempgb1[6][3], tempgb2[6][3], tempgb3[6], tempgc1[29][2], tempgc2[29][5],
        tempgc3[29][5], tempgc4[29][2], nup_four_cg31[14], nup_four_cg32[16],
        nup_four_cg33[17], nup_four_cg34[18], nup_four_cg35[19], nup_four_cg36[20],
        nup_four_cg37[21], nup_four_cg38[22], nup_four_cg39[23];
extern const int tempga4[9], tempgb4[6];

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

class GachaHelper {
public:
    GachaHelper();
    virtual void GachaGacha(BannerType chosen_banner, int64_t chosen_event_p) = 0;
    Rarity GetRarity() { return m_current_rarity; };
    int GetItemId() { return item_id; };
protected:
    virtual void InitHelper() = 0;
    virtual void PoolStair(int chosen_event) = 0;
    virtual void SetPool(const int64_t sw, const size_t size_nup_four_c_p,
        const int* nup_four_cgm) = 0;
    void Init();
    void ini_ams(int* in, size_t ins, const int* out);

    void set_pool_2(const int64_t sw, const int size_nup_four_c_p,
        const int* nup_four_cgm);
    void set_pool_3(const int64_t sw, int size_nup_four_c_p,
        const int* nup_four_cgm);
    void pool_stair_2(int64_t chosen_banner_p);
    void pool_stair_3(int64_t chosen_banner_p);
    void pool_stair_4(int64_t chosen_banner_p);

    //  随机返回入参中的一个成员
    int ResultPick(const int* kindx, size_t sizekind);

    //  加权随机采样
    Rarity WRSpick(const std::vector <int>& weight, bool is_character);

    void core_f_3();
    void core_f_4();
    void core_f_5();
    void post_add();
    //void SetBanner(BannerType chosen_banner, int64_t chosen_event_p);
    void GachaInit(BannerType chosen_banner, int64_t chosen_event_p);
    int SetFateWeapon(const unsigned int fate_weapon);

    bool is_noelle;
    bool is_five_star_guarantee;  //  标记下一次五星是否是大保底
    bool is_four_star_guarantee;  //  标记下一次四星是否是大保底
    int item_id, item_kind_symbol, fate_points, up_item_id,
        countx;
    int four_star_assurance_number,  //  此前多少抽没有抽到四星
        five_star_assurance_number;  //  此前多少抽没有抽到五星
    int m_fate_weapon;
    Rarity m_current_rarity;
    std::vector<int> all_four_star_character;  //  当期所有四星角色，包括up角色
    //  TODO 用于校验是否需要重置保底，后面改个名
    std::vector<int> five_check;
    std::vector<int> four_check;

    std::vector<int> probability_increased_five_stars;  //  当期UP五星
    std::vector<int> probability_increased_four_stars;  //  当期UP四星 
    signed int error_code;
    int unmet5_w;
    int unmet5_c;
    int four_star_character_counter;
    int four_star_weapon_counter;
};

class CharacterGachaHelper : public GachaHelper {
public:
    CharacterGachaHelper() {
        InitHelper();
    }
    void SetBanner(int chosen_event);
    virtual void GachaGacha(BannerType chosen_banner, int64_t chosen_event_p);
    
protected:
    virtual void InitHelper();
    virtual void PoolStair(int chosen_event);
    virtual void SetPool(const int64_t sw, const size_t size_nup_four_c_p,
        const int* nup_four_cgm);
    //  角色祈愿
    void CharacterEventWish();
};

class WeaponGachaHelper : public GachaHelper {
public:
    virtual void GachaGacha(BannerType chosen_banner, int64_t chosen_event_p) {};

protected:
    virtual void InitHelper() {};
    virtual void PoolStair(int chosen_event) {};
    virtual void SetPool(const int64_t sw, const size_t size_nup_four_c_p,
        const int* nup_four_cgm) {};
};

class StandardGachaHelper : public GachaHelper {
public:
    virtual void GachaGacha(BannerType chosen_banner, int64_t chosen_event_p) {};

protected:
    virtual void InitHelper() {};
    virtual void PoolStair(int chosen_event) {};
    virtual void SetPool(const int64_t sw, const size_t size_nup_four_c_p,
        const int* nup_four_cgm) {};
};

class BeginnerGachaHelper : public GachaHelper {
public:
    virtual void GachaGacha(BannerType chosen_banner, int64_t chosen_event_p) {};

protected:
    virtual void InitHelper() {};
    virtual void PoolStair(int chosen_event) {};
    virtual void SetPool(const int64_t sw, const size_t size_nup_four_c_p,
        const int* nup_four_cgm) {};
};

class GachaHelperFactor {
public:   
    ~GachaHelperFactor() {
        for (auto& helper : m_helpers) {
            delete helper.second;
        }
    }
    gacha::GachaHelper* GetHelper(BannerType chosen_banner);
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
