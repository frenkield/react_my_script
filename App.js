import React, {Component} from 'react'
import {Button, StyleSheet, Text, View, TouchableHighlight, Alert, Picker, Modal} from 'react-native'
import SingleCharWidget from './SingleCharWidget'

export default class App extends Component<{}> {

    constructor(props) {

        super(props)

        const defaultGridSize = 5

        this.state = {
            gridSize: defaultGridSize,
            cells: [],
            cellSize: 50,
            gridSizeSelectorVisible: false,
            cellSizeSelectorVisible: false,
            cells: App.generateGrid(defaultGridSize)
        }
    }

    showGridSizeSelector(visible) {
        this.setState({gridSizeSelectorVisible: visible, newSize: this.state.gridSize})
    }

    updateGridSize(newSize) {
        const cells = App.generateGrid(newSize)
        this.setState({gridSize: newSize, cells: cells, gridSizeSelectorVisible: false})
    }

    showCellSizeSelector(visible) {
        this.setState({cellSizeSelectorVisible: visible, newSize: this.state.cellSize})
    }

    updateCellSize(newSize) {
        this.setState({cellSize: newSize, cellSizeSelectorVisible: false})
    }

    static generateGrid(gridSize) {

        const cells = []

        for (let i = 0; i < gridSize; i++) {

            const row = []
            cells.push(row)

            for (let j = 0; j < gridSize; j++) {
                if (Math.random() > 0.2) {
                    row.push(1)
                } else {
                    row.push(0)
                }
            }
        }

        return cells;
    }

    changeCellSize() {
        this.setState({cellSize: 30})
    }

    render() {

        return (

            <View style={styles.container}>

                <Text style={styles.header}>
                    Crossword
                </Text>

                <Text style={styles.info}>
                    Grid Size: {this.state.gridSize} x {this.state.gridSize}
                </Text>

                <Text style={styles.info}>
                    Cell Size: {this.state.cellSize} x {this.state.cellSize}
                </Text>

                {/*<View onStartShouldSetResponder={() => this.addCell()} style={{backgroundColor: 'green', width: 200, height: 200}}>*/}
                {/*</View>*/}

                <View style={styles.grid}>
                    {this.renderGrid()}
                </View>

                {this.renderSizeSelector('Set Grid Size', 1, 50,
                    (newSize) => this.updateGridSize(newSize), this.state.gridSizeSelectorVisible)}

                {this.renderSizeSelector('Set Cell Size', 10, 100,
                    (newSize) => this.updateCellSize(newSize), this.state.cellSizeSelectorVisible)}

                <View style={styles.buttonContainer}>
                    <Button title="Change Grid Size" style={styles.button} onPress={() => this.showGridSizeSelector(true)}/>
                </View>

                <View style={styles.buttonContainer}>
                    <Button title="Change Cell Size" style={styles.button} onPress={() => this.showCellSizeSelector(true)}/>
                </View>

                <View style={styles.buttonContainer}>
                    <Button title="Show Alert" style={styles.button} onPress={() => Alert.alert('Alert!', 'Alert Example')}/>
                </View>

            </View>
        )
    }

    renderSizeSelector(title, minSize, maxSize, updateSize, visible) {

        const sizes = [...Array(maxSize - minSize).keys()].map(key => key + minSize)

        return (

            <Modal visible={visible} animationType={'fade'} transparent={true}
                   onRequestClose={() => this.closeSizeSelector()}>

                <View style={styles.modalContainer}>
                    <View style={styles.modalInnerContainer}>

                        <Text style={styles.subHeader}>{title}</Text>

                        <Picker selectedValue={this.state.newSize} style={styles.sizePicker}
                                onValueChange={(itemValue, itemIndex) => this.setState({newSize: itemValue})}>

                            {sizes.map(size =>
                                <Picker.Item label={`${size}`} value={size} key={size} />
                            )}

                        </Picker>

                        <View style={styles.buttonContainer}>
                            <Button title="Select Size" style={styles.button} onPress={() => updateSize(this.state.newSize)}/>
                        </View>

                    </View>

                </View>

            </Modal>
        )
    }

    renderGrid() {
        return (
            this.state.cells.map((row, rowIndex) =>
                <View style={styles.row} key={'row-' + rowIndex}>
                    {this.renderGridRow(row, rowIndex)}
                </View>
            )
        )
    }

    renderGridRow(row, rowIndex) {
        return (
            row.map((cell, columnIndex) => {

                if (cell === 1) {

                    return <SingleCharWidget
                        style={[styles.characterCell, {width: this.state.cellSize, height: this.state.cellSize}]}
                        key={'cell-' + rowIndex + '-' + columnIndex}/>

                } else {

                    return <View
                        style={[styles.blackCell, {width: this.state.cellSize, height: this.state.cellSize}]}
                        key={'cell-' + rowIndex + '-' + columnIndex}/>
                }
            })
        )
    }
}

const styles = StyleSheet.create({

    container: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        backgroundColor: '#F5FCFF',
        margin: 5
    },

    characterCell: {
        backgroundColor: 'white',
        borderWidth: 1
    },

    blackCell: {
        backgroundColor: 'black',
        borderWidth: 1
    },

    grid: {
        flex: 1,
        flexDirection: 'row',
        flexWrap: 'wrap',
        margin: 20
    },

    header: {
        fontSize: 30,
        fontWeight: 'bold',
        textAlign: 'center',
        marginTop: 20,
        marginBottom: 10
    },

    subHeader: {
        fontSize: 20,
        fontWeight: 'bold',
        textAlign: 'center',
        marginTop: 10,
        marginBottom: 10
    },

    buttonContainer: {
        width: 200,
        margin: 5,
        backgroundColor: '#eeeeee'
    },

    button: {
        color: '#ffffff'
    },

    sizePicker: {
        width: 100,
        borderWidth: 1
    },

    modalContainer: {
        flex: 1,
        flexDirection: 'column',
        justifyContent: 'center',
        alignItems: 'center',
        backgroundColor: '#00000070'
    },

    modalInnerContainer: {
        alignItems: 'center',
        backgroundColor: 'white',
        borderRadius: 10
    }
})
