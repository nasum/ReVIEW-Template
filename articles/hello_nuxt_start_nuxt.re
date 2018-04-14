
= Nuxt.jsのはじめ方

//lead{
この章では@<ttb>{Nuxt.js}のプロジェクトのはじめ方を解説していきます。大きく分けると何もない状態から@<ttb>{npm}を使う方法と、@<ttb>{vue-cli}という@<ttb>{Vue.js}のプロジェクトを作るためのコマンドラインツールを使う方法があります。それぞれについて見ていきたいと思います。
//}

== npmを使う

@<ttb>{npm}を使ってゼロから@<ttb>{Nuxt.js}を開発していく環境を創って行きたいと思います。まずは@<ttb>{npm init}をしてプロジェクトを開始していきます。

//cmd{
$ npm init
//}

次に@<ttb>{Nuxt.js}をインストールします。

//cmd{
$ npm install --save nuxt
//}

@<ttb>{--save}をつけてインストールします。

その後@<ttb>{Nuxt.js}の作法にしたがったディレクトリ構成でディレクトリを作成することで開発を進めることができます。ディレクトリ構成に関しては第3章で詳しく見ていく予定です。

今回は最低限必要なディレクトリである@<ttb>{pages}ディレクトリを作成していきます。

//cmd{
$ mkdir pages
//}

@<ttb>{pages}ディレクトリを作成したら、その中に最初のページを作成します。@<ttb>{pages}ディレクトリの中に配置するのは@<ttb>{.vue}ファイルです。@<ttb>{.vue}ファイルは@<ttb>{template}・@<ttb>{script}・@<ttb>{style}をひとつにまとめたファイルで、単一ファイルコンポーネントと呼ばれます。@<ttb>{index.vue}を作成して次のように書きます。

//list[first_vue][index.vue][html]{
<template>
<div>
  <h1>Hello Nuxt !!</h1>
</div>  
</template>
//}

次に@<ttb>{Nuxt.js}を実行できるように@<ttb>{package.json}の@<ttb>{script}に@<ttb>{Nuxt.js}を実行するコマンドを書きます。

//list[package.json][package.json][json]{
{
  // 略
  "scripts": {
    "dev": "nuxt dev",
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  // 略
}
//}

これで@<ttb>{Nuxt.js}を実行できるようになります。次のコマンドで実行してみます。

//cmd{
$ npm run dev
//}

コマンドを実行したあと@<ttb>{https://localhost:3000}をブラウザで開いてみると次のように表示されるはずです。

//image[02_01][Hello Nuxt !! と表示される]{
  Hello Nuxt !!
//}

これで@<ttb>{Nuxt.js}を用いた最低限のアプリケーションの作成ができました。後述する指定されたディレクトリ構成でディレクトリを作成し、コードを書くことで今後の開発を進めていきます。

== vue-cliを使う

@<ttb>{npm}を使ってゼロから作成すると当たり前の話ですが自分で全て作らないといけないため、プロジェクト作成のスピード感は遅くなりがちです。@<ttb>{vue-cli}を使い公式の@<ttb>{Nuxt.js}のテンプレートを使用することで必要なディレクトリ構成が初めから用意された状態でプロジェクトをはじめることができます。

まずは@<ttb>{vue-cli}をグローバルのパッケージにインストールします。次のコマンドでインストールを行います。

//cmd{
$ npm install -g @vue/cli
//}

今回使用する@<ttb>{vue-cli}のバージョンは@<ttb>{3.0.0-beta.6}です。

//cmd{
$ vue --version
3.0.0-beta.6
//}

@<ttb>{vue-cli}を使用してプロジェクトを開始していきます。@<ttb>{Nuxt.js}のテンプレートを使用してプロジェクトを開始していこうと思うのですが、@<ttb>{vue-clie}の@<ttb>{init}コマンドは@<ttb>{vue-clie}のバージョンが3系ではdeprecatedになっています。ですがまだ@<ttb>{Nuxt.js}のテンプレートが新しいものに対応されていないので@<ttb>{init}コマンドを使用できるようにしてテンプレートからプロジェクトを作成できるようにします。

次のコマンドで@<ttb>{init}コマンドをインストールします。

//cmd{
$ npm install -g @vue/cli-init
//}

これでレガシーな@<ttb>{init}コマンドが使用できるようになります。次のコマンドを実行し、テンプレートからプロジェクトを作成します。

//cmd{
$ vue init nuxt-community/starter-template vue-cli

? Target directory exists. Continue? Yes
? Project name vue-cli
? Project description Nuxt.js project
? Author nasum <tomato.wonder.life@gmail.com>

   vue-cli · Generated "vue-cli".

   To get started:

     cd vue-cli
     npm install # Or yarn
     npm run dev


$                                                       
//}

いくつかの質問を得てプロジェクトが作成されます。テンプレートから必要なファイルが自動生成され、すぐに動く状態でセットアップされました。次のコマンドで実行してみます。

//cmd{
$ npm install # 必要なパッケージをまずはインストール
$ npm run dev # nuxtを実行するnpm script
//}

コマンドを実行したあと@<ttb>{https://localhost:3000}をブラウザで開いてみると次のように表示されるはずです。

//image[02_02][vue-cliで作成したものを実行した結果]{
  vue-cli
//}

これで全てが用意された@<ttb>{Nuxt.js}のプロジェクトが作成されました。ディレクトリ構成等必要なものは生成されていますが、@<ttb>{.vue}ファイル等は必要最低限のものが用意されているだけなので、それを編集するだけで自分の@<ttb>{Nuxt.js}のプロジェクトを開始することができます。特別な理由がない限り@<ttb>{vue-cli}でテンプレートをもとにプロジェクトを開始するほうがスピーディでよいと思われます。

== まとめ

以上@<ttb>{Nuxt.js}でのプロジェクト開始方法を解説していきました。何もない状態から作成するのであれば@<ttb>{vue-cli}を使ったほうがスピーディにプロジェクトを開始できるのでお薦めです。すでに@<ttb>{Vue.js}でアプリケーションを作っていて、それを@<ttb>{Nuxt.js}でSSRするなどの要件がある場合は@<ttb>{npm}でプロジェクトを開始するのがよいでしょう。書くプロジェクトに適した形ではじめられるのがよいでしょう。