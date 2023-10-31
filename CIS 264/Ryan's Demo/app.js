
'use strict';

const e = React.createElement;

class Cabin extends React.Component {
    render() {
        return e('div', null, `Cabin Name: ${this.props.name}`);
    }
}

const cabins = ['Cozy Cabin', 'Rustic Cabin', 'Modern Cabin'];
const cabinComponents = cabins.map(name => e(Cabin, { name }));

const domContainer = document.querySelector('#root');
ReactDOM.render(cabinComponents, domContainer);