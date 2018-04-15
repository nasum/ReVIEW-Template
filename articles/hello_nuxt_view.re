= Nuxt.jsでのビューコンポーネントについて

//lead{
この章では@<ttb>{Nuxt.js}のビューコンポーネントについて解説していきます。@<ttb>{Nuxt.js}ではサーバーサイドレンダリングを行うために@<ttb>{.vue}ファイルを拡張しています。本章では@<ttb>{Nuxt.js}におけるビューコンポーネントについて書いていきます。
//}

== ビューコンポーネント

@<ttb>{Nuxt.js}でページを定義するのは@<ttb>{pages}ディレクトリに配置された@<ttb>{.vue}ファイルです。

== コンテキスト

== .vueファイルに追加された属性

@<chapref>{hello_nuxt_directory}でも軽く触れましたが@<ttb>{Nuxt.js}では@<ttb>{.vue}ファイルに独自の拡張を加えます。

@<ttb>{.vue}ファイルは次のように書くことができます。

//list[vue][index.vue][javascript]{
<script>
export default {
  asyncData (params) {
    // コンポーネントにデータをセットする前に非同期な処理を行う
  },
  fetch () {
    // ページがレンダリングされる前にストアにデータをセットする処理を行う
  },
  head () {
    // アプリケーションのheadタグを設定する処理を書く
  },
  layout: 'layout-name',
  transition: 'transition-name',
  scrollToTop: true,
  validate () {
    // ルーティングパラメータのバリデーション
  },
  middleware: 'middleware-name'
}
</script>
//}

それぞれの属性について詳しく見ていきます。

=== asyncData

@<ttb>{asyncData}は@<ttb>{Vuex}のストアを使わずに、データを取得しレンダリングの事前処理をするときに使用します。@<ttb>{asyncData}はページコンポーネントがロードされるたびに呼び出されます。サーバサイドレンダリング時にも呼び出されます。

@<ttb>{asyncDate}内で取得したデータはページコンポーネントの@<ttb>{data}とマージすることができできます。

@<ttb>{asyncDate}は次の方法で実装します。

1. @<ttb>{Promise}を返す
2. @<ttb>{aync/await}を使用する
3. 第二引数としてコールバック関数を定義する


==== Promiseを返す

@<ttb>{Promise}を返す実装を次に示します。

//list[async_data][index.vue][html]{
<template>
  <section>
    <h1>sample</h1>
    {{ title }}
  </section>
</template>

<script>
export default {
  asyncData(params) {
    return new Promise((resolve, reject) => {
      // ここに非同期処理を書く
      resolve();
    }).then(() => {
      return {
        title: "sample_text"
      };
    });
  }
};
</script>
//}

@<ttb>{return} でマージするオブジェクトを返します。@<ttb>{title}が@<ttb>{template}内で使用されて次のように表示されることがわかります。

//image[04_01][sample_textと表示される]{
  sample_text
//}

==== async/awaitを使用する

同じ例を@<ttb>{async/await}を使用して実装を行います。

//list[async_await_data][index.vue][html]{
<template>
  <section>
    <h1>sample</h1>
    {{ title }}
  </section>
</template>

<script>
async function fn() {
  return {
    title: "sample_text"
  };
}

export default {
  async asyncData(params) {
    const result = await fn();
    return result;
  }
};
</script>
//}

==== コールバックを使用する

同じ例を@<ttb>{callback}を使用して実装します。第一引数はエラーオブジェクト、第二引数にはマージするデータをセットします。

//list[async_await_callback][index.vue]{
<template>
  <section>
    <h1>sample</h1>
    {{ title }}
  </section>
</template>

<script>
async function fn() {
  return {
    title: "sample_text"
  };
}

export default {
  asyncData({ params }, callback) {
    fn().then(res => {
      callback(null, { title: res.title });
    });
  }
};
</script>
//}

=== fetch

@<ttb>{fetch}はページがレンダリングされる前にデータを@<ttb>{store}に入れるために使用されます。ここで定義された関数もページコンポーネントがロードされるたびに呼び出されます。

@<ttb>{fetch}関数は第一引数にコンテキストを受け取り、コンテキストを使用してデータを@<ttb>{store}に入れます。

//list[fetch][index.vue]{
<template>
<section>
  <h1>sample</h1>
  {{ $store.state.title }}
</section>
</template>

<script>
export default {
  fetch ({ store, params }) {
    return axios.get('http://example.com/api/title').then(() => {
      store.commit('setTitle', { title: res.title })
    });
  }
}
</script>
//}

=== head

=== layout

=== transition

=== scrollToTop

=== validate

=== middleware