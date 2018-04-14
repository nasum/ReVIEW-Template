
= ディレクトリ構成と役割

//lead{
この章では@<ttb>{Nuxt.js}のディレクトリ構成について解説していきます。@<ttb>{Nuxt.js}は推奨されるディレクトリ構成がすでに決まっており、ビルド時にそれぞれのディレクトリごとの役割にしたがってビルドされます。ディレクトリの役割について解説していきます。
//}

== pages

@<ttb>{Nuxt.js}の中で基本的で一番重要なディレクトリは@<ttb>{pages}ディレクトリです。@<ttb>{pages}ディレクトリはビューとルーティングに関する役割を負います。

ビューとルーティングについて詳しく見ています。

=== ビュー

@<ttb>{pages}ディレクトリに配置される@<ttb>{.vue}ファイルはそれがひとつのページになります。これをページコンポーネントと呼びます。

@<ttb>{Nuxt.js}はユニバーサルアプリケーションを作成するために@<ttb>{.vue}ファイルに独自の属性を追加します。独自に追加された属性を次に挙げます。

 : asyncData	
    コンポーネントがロードされるたびに呼び出される。主にレンダリングの前処理に使用する
 : fetch
		ページがレンダリングされる前にデータをストアに入れるために使用される
 : head
		ページに対してmetaタグを設定するために使用される
 : layout
		layoutをしているするために使用される
 : transition
		ページ特定のトランジションを設定するために使用される
 : scrollToTop
		ページをレンダリングする前にページを一番上までスクロールするか設定できる
 : validate
		動的なルーティングをするための検証関数を設定できる
 : middleware
		ページをレンダリングする前に実行するmiddlewareを設定する

それぞれの項目に関してはビューの章で細かく見ていきます。

=== ルーティング

@<ttb>{Nuxt.js}はビルド時にこのディレクトリ中のファイル名やディレクトリ名にしたがってルーティングを自動生成します。

たとえば次のようなディレクトリを@<ttb>{pages}ディレクトリ中に作ります。

//emlist[ディレクトリ構成]{
pages
├─ articles
│　└─ index.vue
├─ about.vue
└─ index.vue
//}

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

この状態で@<ttb>{nuxt dev}を実行すると次のURLでアクセスできるようになります。

 * @<ttb>{/} pages直下の@<ttb>{index.vue}が表示される
 * @<ttb>{/about} pages直下の@<ttb>{about.vue}が表示される
 * @<ttb>{/articles} articles配下の@<ttb>{index.vue}が表示される

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

このようにディレクトリとファイル構成で自動的にルーティングを作成し、ビューを表示することができます。

== components

@<ttb>{components}ディレクトリにはビューで使用するためのコンポーネントを配置します。

@<ttb>{components}ディレクトリは@<ttb>{Nuxt.js}からは自動で読み込まれないため、使用しなければ削除することが可能です。

ここに配置されるコンポーネントは@<ttb>{Nuxt.js}の影響下ではないため、ピュアな@<ttb>{.vue}ファイルになります。

== layouts

@<ttb>{layouts}ディレクトリはアプリケーションのレイアウトとなるファイルを入れます。

=== デフォルトレイアウト

デフォルトのレイアウトは@<ttb>{default.vue}という名前で作成します。レイアウトの中身は次のように書いていきます。

//list[default][defualt.vue][html]{
<template>
  <nuxt/>
</template>
//}

@<ttb>{<nuxt/>}は@<ttb>{Nuxt.js}で定義されたコンポーネントでレイアウトファイルないでのみページコンポーネントを表示するために使用します。

=== エラーページ

エラーページは@<ttb>{error.vue}という名前で作成します。エラーページで使用するため@<ttb>{<nuxt/>}を含めてはいけません。次のようにエラーページは書いていきます。

//list[error][error.vue][html]{
<template>
  <div>
    <h1 v-if="error.statusCode === 404">ページが見つかりません</h1>
    <h1 v-else>エラーが発生しました</h1>
  </div>
</template>
<script>
export default {
  props: ['error']
}
</script>
//}

@<ttb>{error.vue}は@<ttb>{props}として@<ttb>{error}を受け取ります。@<ttb>{error}オブジェクトは次の値を持ちます。

 : message
    エラーメッセージが入ります
 : path
    エラーが発生したパスが入ります
 : statusCode
    エラーコードが入ります ex.. 404

@<ttb>{statusCode}で表示するメッセージを分岐するなどしてエラー時のページを表示し分けます。

=== カスタムレイアウト

ページごとにカスタマイズしたレイアウトを作成することができます。レイアウトは@<ttb>{<nuxt/>}を必ず含みます。

書き方自体はデフォルトレイアウトと同じですが、ページコンポーネントの@<ttb>{layout}にカスタムレイアウトのファイル名を書きます。実装は次のように行います。

//list[article_layout][article_layout.vue][html]{
<template>
  <div>
    article layout
    <nuxt/>
  </div>
</template>
//}

//list[article_index][index.vue][html]{
<template>
  <section>
    <h1>articles</h1>
  </section>
</template>

<script>
export default {
  layout: "article_layout"
};
</script>
//}

== plugin

@<ttb>{plugins}ディレクトリにはアプリケーションをインスタンス化する前に実行したい@<ttb>{JavaScript}プラグインを配置します。

サードパーティの@<ttb>{Vue Plugin}などを利用するときにここに初期化のコードを書きます。たとえば@<ttb>{vue-good-table}というプラグインを使用する場合@<ttb>{plugins}ディレクトリに次のようなファイルを配置します。

//list[vue-good-table][vue-good-table.js][javascript]{
import Vue from 'vue';

import VueGoodTable from 'vue-good-table';
import 'vue-good-table/dist/vue-good-table.css'

Vue.use(VueGoodTable);
//}

@<ttb>{vue-good-table}のコンポーネントを使用するには次のように書きます。

//list[index][index.vue][html]{
<template>
  <section>
    <h1>Hello Nuxt!!</h1>
    <vue-good-table
      :columns="columns"
      :rows="rows"
      :search-options="{
        enabled: true,
      }"
      :pagination-options="{
        enabled: true,
        perPage: 5,
      }"
      styleClass="vgt-table striped bordered"/>
  </section>
</template>
//}

これで@<ttb>{vue-good-table}のコンポーネントがどのページコンポーネントでも使用できます。

他にもカスタムディレクティブ等グローバルで使用するものはここで定義します。

== middleware

@<ttb>{middleware}ディレクトリにはページをレンダリングするよりも前に実行される関数を定義し配置することができます。たとえば次のように@<ttb>{console.log}で出力する関数を定義します。

//list[visit][visit.js][javascirpt]{
export default function () {
  console.log('visit')
}
//}

これを使用するためにページコンポーネントの@<ttb>{middleware}キーにファイル名を記入します。

//list[index_visit][index.vue][javascript]{
<script>
export default {
  middleware: ["visit"]
};
</script>
//}

するとこのコンポーネントをレンダリングするたびに@<ttb>{console.log}が呼び出され@<ttb>{Nuxt.js}を実行したコンソール上で@<ttb>{visit}と表示されます。

#@# コンテキストについてどうするか

気をつけなければいけないのは@<ttb>{middleware}はサーバサイド側で実行されるという点です。クライアントサイドで使えるような関数（@<ttb>{alert}等）は使えないことに気をつけましょう。

用途としてはページがレンダリングされるより前の認証処理を実行するさいに使用するのがよいでしょう。

== store

== assets

== static

== まとめ