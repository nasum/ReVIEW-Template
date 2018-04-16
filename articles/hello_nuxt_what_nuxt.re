
= Nuxt.jsとは

//lead{
@<ttb>{Nuxt.js}とは一体どのようなフレームワークなのでしょうか。この章では@<ttb>{Nuxt.js}が実現するユニバーサルアプリの概念と、機能として実装されているサーバーサイドレンダリングと静的ファイルジェネレータについて解説していきます。
//}

== ユニバーサルアプリ

@<ttb>{Nuxt.js}とはユニバーサルなアプリケーションを構築するためのフレームワークです。@<ttb>{Vue.js}をその技術の中心に置き開発していくことが可能です。

ではユニバーサルなアプリケーションとは一体なんでしょうか？

ここでいうユニバーサルなアプリケーションとはクライアントサイドとサーバーサイドの両方で実行できる@<ttb>{JavaScript}のアプリケーションをさします。かつてはisomophicと呼ばれていた概念です。ユニバーサルなアプリケーションの場合はもう少し拡張して同じコードをネイティブアプリやデスクトップアプリでも実行できるようにしようという試みもあります。

さらに誤解を恐れずに簡単にいうと、同じ@<ttb>{JavaScript}のコードでクライアントサイドのSPAとサーバサイドのサーバサイドレンダリングを実現してしまうというものです。

@<ttb>{Nuxt.js}の場合は@<ttb>{Vue.js}でビューを構築し、@<ttb>{Nuxt.js}のレールを利用することで簡単にユニバーサルなアプリケーションを実現することができます。

== サーバーサイドレンダリング

@<ttb>{Nuxt.js}はプロジェクトのUIレンダリングを担うフロントエンドサーバーとして使用することができます。

UIレンダリングを@<ttb>{Nuxt.js}で構築したフロントエンドサーバーに任せ、動的な情報はバックエンドサーバーから取得するという設計で行うことができます。@<ttb>{Nuxt.js}ではサーバーサイドレンダリングをするために事前に情報をバックエンドサーバーから取得するための機能があります。ページコンポーネントの@<ttb>{asyncData}メソッドや@<ttb>{fetch}メソッドで情報を取得します。それらについては@<chapref>{hello_nuxt_view}で詳しく見ていきます。

また@<ttb>{Nuxt.js}をミドルウェアとして使用し、@<ttb>{express}などのアプリケーションサーバーから使用することも可能です。

== 静的ファイルジェネレータ

@<ttb>{Nuxt.js}は静的ファイルジェネレータとしても使うことができます。@<ttb>{pages}ディレクトリ中のページコンポーネントをそのまま@<ttb>{HTML}ファイルとして出力できます。出力された静的ファイルは@<ttb>{Vue.js}や@<ttb>{Vuex}を含んでいるのでWebアプリケーションとして動作させることができます。

また@<ttb>{HTML}として出力されたことにより、@<ttb>{firebase hosting}や@<ttb>{GitHub Pages}にホストすることができます。静的ファイルホスティングサービスを利用することによりサーバーレスなWebアプリケーションを簡単に作成できるようになります。

== まとめ

以上@<ttb>{Nuxt.js}について見ていきました。ユニバーサルアプリとは何かや@<ttb>{Nuxt.js}というフレームワークについて見ていきました。

@<ttb>{Nuxt.js}はサーバサイドレンダリングを行うフロントエンドサーバーとして利用することや、静的ファイルジェネレータとして活用し、サーバレスなアプリケーションを作成するなどさまざまな利用が可能です。プロジェクトに応じた利用の仕方をしていくとよいでしょう。


