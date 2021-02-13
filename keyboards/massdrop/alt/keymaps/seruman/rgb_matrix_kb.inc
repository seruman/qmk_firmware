RGB_MATRIX_EFFECT(finger_positions)
RGB_MATRIX_EFFECT(off)


#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define RED {HSV_RED}
#define CORAL {HSV_CORAL}
#define ORANGE {HSV_ORANGE}
#define GOLDEN {HSV_GOLDENROD}
#define GOLD {HSV_GOLD}
#define YELLOW {HSV_YELLOW}
#define CHART {HSV_CHARTREUSE}
#define GREEN {HSV_GREEN}
#define SPRING {HSV_SPRINGGREEN}
#define TURQ {HSV_TURQUOISE}
#define TEAL {HSV_TEAL}
#define CYAN {HSV_CYAN}
#define AZURE {HSV_AZURE}
#define BLUE {HSV_BLUE}
#define PURPLE {HSV_PURPLE}
#define MAGENT {HSV_MAGENTA}
#define PINK {HSV_PINK}
#define OFF {HSV_PURPLE}


const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {
        YELLOW,  YELLOW,  YELLOW,  RED,     GREEN,   BLUE,     BLUE,   PURPLE,  PURPLE,  GREEN,   RED,     YELLOW,  YELLOW,  YELLOW,  YELLOW,
        YELLOW,  YELLOW,  RED,     GREEN,   BLUE,    BLUE,     PURPLE, PURPLE,  GREEN,   RED,     YELLOW,  YELLOW,  YELLOW,  YELLOW,  YELLOW,
        YELLOW,  YELLOW,  RED,     GREEN,   BLUE,    BLUE,     PURPLE, PURPLE,  GREEN,   RED,     YELLOW,  YELLOW,           YELLOW,  YELLOW,
        YELLOW,  YELLOW,  RED,     GREEN,   BLUE,    BLUE,     PURPLE, PURPLE,  GREEN,   RED,     YELLOW,  YELLOW,           YELLOW,  YELLOW,
        YELLOW,  TEAL,    TEAL,                                TEAL,                              TEAL,    YELLOW,  YELLOW,  YELLOW,  YELLOW,
        //UnderGlow
        OFF,     OFF,     OFF,     OFF,     OFF,     OFF,      OFF,    OFF,     OFF,     OFF,     OFF,     OFF,     OFF,     OFF,     OFF,
        OFF,                                                                                                                          OFF,
        OFF,                                                                                                                          OFF,
        OFF,                                                                                                                          OFF,
        OFF,                                                                                                                          OFF,
        OFF,     OFF,     OFF,     OFF,     OFF,     OFF,      OFF,    OFF,     OFF,     OFF,     OFF,     OFF,     OFF,     OFF,     OFF
    },
};


// TODO(selman): check effect params. e.g: ignore underglow depending on mode
static void set_from_ledmap(int index,  effect_params_t* params, uint8_t min, uint8_t max) {
    for (uint8_t i = min; i < max; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[index][i][0]),
            .s = pgm_read_byte(&ledmap[index][i][1]),
            .v = pgm_read_byte(&ledmap[index][i][2]),
        };
        if (hsv.h || hsv.s || hsv.v) {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

static bool finger_positions(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    set_from_ledmap(0, params, led_min, led_max);
    return led_max < DRIVER_LED_TOTAL;
}

static bool off(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color_all(RGB_OFF);
    return led_max < DRIVER_LED_TOTAL;
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS