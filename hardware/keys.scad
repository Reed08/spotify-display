include <includes.scad>

$font = "Noto Sans Symbols 2:style=Regular";

module media_key(x, symbol) {
  translate_u(x) bar_support() rounded_cherry(0.45) tined_stem_support()
    legend(symbol, size=8) dsa_row() key(true);
}

media_key(0, "⏮");
media_key(1, "⏯");
media_key(2, "⏭");
media_key(3, "❤️");
