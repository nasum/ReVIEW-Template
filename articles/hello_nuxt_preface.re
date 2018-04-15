= はじめに

本書は@<ttb>{Vue.js}でユニバーサルなアプリケーションを構築するためのフレームワーク@<ttb>{Nuxt.js}の入門書です。@<ttb>{Vue.js}と@<ttb>{Vuex}、@<ttb>{vue-route}を触ったことのある人であれば問題なく読むことができるように作成されています。@<ttb>{Vue.js}は触ったことはあるけど@<ttb>{Nuxt.js}は触ったことない、@<ttb>{Nuxt.js}の使いどころがわからないという人が想定読者となっています。

本書を読んで@<ttb>{Nuxt.js}を使用するイメージがつきましたら、@<ttb>{Nuxt.js}のガイド@<fn>{nuxt-guide}が存在するのでそちらの方をさらに閲覧していただけるとよりステップアップがはかれます。特に本書では@<ttb>{Nuxt.js}の設定ファイルである@<ttb>{nuxt.config.js}は扱わないので、細かい設定方法はガイドを参考にするのがよいでしょう@<fn>{why-not-analyze-config}。

//footnote[nuxt-guide][Nuxt.js日本語ガイド https://ja.nuxtjs.org/guide]
//footnote[why-not-analyze-config][なぜ設定ファイルの解説を行わないかというと、Nuxt.jsはデフォルトの設定で十分に使用することが可能だからです。高度な利用をする場合は設定を追加する必要はありますが、本書の扱う範囲を超えてしまうため解説を行いません。]

== 本書の構成

本書の構成は次のようになされています。

 : @<chapref>{hello_nuxt_what_nuxt}
  @<ttb>{Nuxt.js}がどのようなフレームワークなのか解説します。
 : @<chapref>{hello_nuxt_start_nuxt}
  @<ttb>{Nuxt.js}のはじめ方を解説します。
 : @<chapref>{hello_nuxt_directory}
  @<ttb>{Nuxt.js}のディレクトリ構成について解説します。
 : @<chapref>{hello_nuxt_view}
  @<ttb>{Nuxt.js}のビューコンポーネントについて解説します。
 : @<chapref>{hello_nuxt_command}
  @<ttb>{Nuxt.js}で使用するコマンドについて解説します。
 : @<chapref>{hello_nuxt_how_to_create_application}
  @<ttb>{Nuxt.js}でアプリケーションを作成する方法について解説します。

== サンプルコードについて

本書で使用したソースコードは次のURLで閲覧可能です。

https://github.com/nasum/hello_nuxt_sample

== 謝辞
