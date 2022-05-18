#ifndef GIWSCLI_H
#define GIWSCLI_H 1
#include <cstddef>

#include "cn_item.h"
#include "en_item.h"
#include "random_gen.h"
#define MAX_ITEMS 118
#define MAX_WEIGHT 10000

namespace gacha {
    extern const size_t standard_five_star_character[5];  //  常驻五星人物
    extern const size_t standard_five_star_weapon[10];  //  常驻五星武器
    extern const size_t standard_four_star_weapon[32];  //  常驻四星武器
    extern const size_t rare_weapon[13],
        nup_four_cg1[11], nup_four_cg2[13], nup_four_cg3[14], nup_four_cg4[15],
        nup_four_cg5[16], nup_four_cg6[17], nup_four_cg7[18], nup_four_cg8[19],
        nup_four_cg9[20], tempga1[30][3], tempga2[30][3], tempga3[30],
        tempgb1[6][3], tempgb2[6][3], tempgb3[6], tempgc1[29][2], tempgc2[29][5],
        tempgc3[29][5], tempgc4[29][2], nup_four_cg31[14], nup_four_cg32[16],
        nup_four_cg33[17], nup_four_cg34[18], nup_four_cg35[19], nup_four_cg36[20],
        nup_four_cg37[21], nup_four_cg38[22], nup_four_cg39[23];
extern const ptrdiff_t tempga4[9], tempgb4[6];

enum class BannerType {
    Character_Event_Wish,
    Character_Event_Wish_2,
    Weapon_Event_Wish,
    Standard_Wish,
    Beginner_Wish
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

    void Init();
    void ini_ams(size_t* in, size_t ins, const size_t* out);

    void set_pool_1(const ptrdiff_t sw, const size_t size_nup_four_c_p,
        const size_t* nup_four_cgm);
    void set_pool_2(const ptrdiff_t sw, const size_t size_nup_four_c_p,
        const size_t* nup_four_cgm);
    void set_pool_3(const ptrdiff_t sw, size_t size_nup_four_c_p,
        const size_t* nup_four_cgm);
    void pool_stair_1(ptrdiff_t chosen_banner_p);
    void pool_stair_2(ptrdiff_t chosen_banner_p);
    void pool_stair_3(ptrdiff_t chosen_banner_p);
    void pool_stair_4(ptrdiff_t chosen_banner_p);

    //  随机返回入参中的一个成员
    size_t ResultPick(const size_t* kindx, size_t sizekind);

    //  加权随机采样
    Rarity WRSpick(const ptrdiff_t* weightx, bool is_character);

    //  角色祈愿
    void CharacterEventWish();
    void core_f_3();
    void core_f_4();
    void core_f_5();
    void post_add();
    void SetBanner(BannerType chosen_banner, ptrdiff_t chosen_event_p);
    void GachaGacha(BannerType chosen_banner, ptrdiff_t chosen_event_p);
    void GachaInit(BannerType chosen_banner, ptrdiff_t chosen_event_p);
    void CleanUp();
    int SetFateWeapon(const unsigned int fate_weapon);

    bool is_noelle;
    bool is_five_star_guarantee;  //  标记下一次五星是否是大保底
    bool is_four_star_guarantee;  //  标记下一次四星是否是大保底
    size_t item_id, item_kind_symbol, fate_points, up_item_id,
        size_nup_four_c,  //  当期所有四星角色，包括up角色数目，这个后面换成vector可以拿掉
        countx,
         max_fivesth, min_fivesth, max_fivecount, min_fivecount,
        size_nup_four_w, kind_r_ach_11,
        //  TODO 共用，不太合理，后面修改
        probability_increased_five_stars[2],  //  当期UP五星
        probability_increased_four_stars[5],  //  当期UP四星
        all_four_star_character[32],  //  当期所有四星角色，包括up角色
        //  TODO 用于校验是否需要重置保底，后面改个名
        five_check[2], four_check[5],
        pcount[128];
    unsigned int resultu;
    ptrdiff_t four_star_character_counter, four_star_weapon_counter, unmet5_c,
        unmet5_w, switch_e_should_be, switch_e_sav,
        four_star_assurance_number,  //  此前多少抽没有抽到四星
        five_star_assurance_number,  //  此前多少抽没有抽到五星
        m_five_weight,  //  五星权重
        m_four_weight,  //  四星权重
        m_three_weight,  //  三星权重
        m_fate_weapon, hash_out[9];
    Rarity m_current_rarity;
    signed int error_code;
};

#if CN_ITEM_H
extern const char *s_pname_cn[128], *s_pnameshort_cn[128], *s_pdetails_cn[128];
#endif
#if EN_ITEM_H
extern const char *s_pname_en[128], *s_pnameshort_en[128], *s_pdetails_en[128];
#endif
}  // namespace giwscli
#endif
