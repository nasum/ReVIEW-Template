
= ディレクトリ構成と役割

//lead{
この章では@<ttb>{Nuxt.js}のディレクトリ構成について解説していきます。@<ttb>{Nuxt.js}は推奨されるディレクトリ構成がすでに決まっており、ビルド時にそれぞれのディレクトリごとの役割にしたがってビルドされます。ディレクトリの役割について解説していきます。
//}

== pages

@<ttb>{Nuxt.js}の中で基本的で一番重要なディレクトリは@<ttb>{pages}ディレクトリです。@<ttb>{pages}ディレクトリはビューとルーティングに関する役割を負います。

@<ttb>{pages}ディレクトリに配置される@<ttb>{.vue}ファイルはそれがひとつのページになります。そして@<ttb>{Nuxt.js}はビルド時にこのディレクトリ中のファイル名やディレクトリ名にしたがってルーティングを自動生成します。

たとえば次のようなディレクトリを@<ttb>{pages}ディレクトリ中に作ります。

//emlist[ディレクトリ構成]{
pages
├─ articles
│　└─ index.vue
├─ about.vue
└─ index.vue
//}

この状態で@<ttb>{nuxt dev}を実行すると次のURLでアクセスできるようになります。

 * @<ttb>{/} pages直下の@<ttb>{index.vue}が表示される
 * @<ttb>{/about} pages直下の@<ttb>{about.vue}が表示される
 * @<ttb>{/articles} articles配下の@<ttb>{index.vue}が表示される

生成されるルーティングのコードを見てみます。@<ttb>{.nuxt/router.js}に次のように生成されます。

//list[router][router.js][javascript]{
import Router from 'vue-router'

Vue.use(Router)
// 略
export function createRouter () {
  return new Router({
    mode: 'history',
    base: '/',
    linkActiveClass: 'nuxt-link-active',
    linkExactActiveClass: 'nuxt-link-exact-active',
    scrollBehavior,
    routes: [
      {
        path: "/about",
        component: _d1429fa2,
        name: "about"
      },
      {
        path: "/articles",
        component: _74e73864,
        name: "articles"
      },
      {
        path: "/",
        component: _91d2ea18,
        name: "index"
      }
    ],


    fallback: false
  })
}
//}

出力されたコードから@<ttb>{vur-router}を使用してルーティングの設定をしていることがわかります。@<ttb>{pages}ディレクトリの中に新しいファイルを作ると、@<ttb>{routes}プロパティの配列が変更されます。

== components

== layouts

== plugin

== middleware

== store

== assets

== static

== まとめ