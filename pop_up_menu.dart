 PopupMenuButton(
   child: Container( 

   ),
    itemBuilder: (_) => <PopupMenuItem<String>>[
          new PopupMenuItem<String>(
              child: const Text('Doge'), value: 'Doge'),
          new PopupMenuItem<String>(
              child: const Text('Lion'), value: 'Lion'),
        ],
    onSelected: _doSomething);

final tile = new ListTile(title: new Text('Doge or lion?'), trailing: button);
