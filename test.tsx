interface Foo {
    id: number;
    name: string;
}

interface Bar<T extends Foo> {
}

interface BarはTの持つpropsをすべて持つことがわかります。
Tがageというpropsを持っていることを確定させるにはinterface Barをどのように定義すればよいでしょうか。