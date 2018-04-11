
= ディレクトリ構成と役割

//lead{
この章では@<ttb>{Nuxt.js}のディレクトリ構成について解説していきます。@<ttb>{Nuxt.js}は推奨されるディレクトリ構成がすでに決まっており、ビルド時にそれぞれのディレクトリごとの役割にしたがってビルドされます。ディレクトリの役割について解説していきます。
//}

== pages

@<ttb>{Nuxt.js}の中で基本的で一番重要なディレクトリは@<ttb>{pages}ディレクトリです。@<ttb>{pages}ディレクトリはビューとルーティングに関する役割を負います。

ビューとルーティングについて詳しく見ています。

=== ビュー

@<ttb>{pages}ディレクトリに配置される@<ttb>{.vue}ファイルはそれがひとつのページになります。

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

=== ルーティング

@<ttb>{Nuxt.js}はビルド時にこのディレクトリ中のファイル名やディレクトリ名にしたがってルーティングを自動生成します。

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

=== 動的なルーティング

パラメータを使って動的なルーティングを定義するにはディレクトリか@<ttb>{.vue}ファイルのプレフィックスに@<ttb>{_}をつけます。

たとえば次のようなディレクトリとファイル構成にしてみます。

//emlist[ディレクトリ・ファイル構成]{
pages
├─ _user
│　└ profile.vue
├─ articles
│　├─ _id.vue
│　└─ index.vue
├─ about.vue
└─ index.vue
//}

この状態で@<ttb>{Nuxt.js}を実行すると次のようなルーティングが生成されます。

//list[router-new][router.js][javascript]{
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
        path: "/articles/:id", // :idに動的に値が入ります
        component: _58dd01b6,
        name: "articles-id"
      },
      {
        path: "/",
        component: _91d2ea18,
        name: "index"
      },
      {
        path: "/:user/profile", // :userに動的に値が入ります
        component: _7386d066,
        name: "user-profile"
      }
    ],


    fallback: false
  })
}
//}

この状態で@<ttb>{nuxt dev}を実行すると次のURLでアクセスできるようになります。

 * @<ttb>{/articles/:id} articles配下の@<ttb>{articles/_id.vue}が表示される
 * @<ttb>{/:user/profile} _user配下の@<ttb>{profile.vue}が表示される

 それぞれの@<ttb>{.vue}ファイルではパラメータの値を表示できますできます。次のようなコードで表示できます。

//list[id][_id.vue][javascript]{
<template>
<div>
  id:{{ $route.params.id }}
</div>
</template>
//}

このようにディレクトリとファイル構成で自動的にルーティングを作成し、ビューを表示することが出来ます。

== components

== layouts

== plugin

== middleware

== store

== assets

== static

== まとめ