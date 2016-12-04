//
//  ViewController.swift
//  Ambrogio
//
//  Created by Gruppioni Michele on 04/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var titleLabel: UILabel!
    @IBOutlet weak var descriptionLabel: UILabel!
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    @IBOutlet weak var textView: UITextView!
    
    let particleURLString = "https://api.particle.io/v1/devices/1a002b000447343337373737/execute"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    @IBAction func didTapTheScreen(_ sender: Any) {
        print("Screen Tapped")
    }
    
    private func sendRequest() {
        
        //let urlRequest = URLRequest(url: NSURL())
        //URLSession.shared.dataTask(with: <#T##URLRequest#>, completionHandler: <#T##(Data?, URLResponse?, Error?) -> Void#>)
    }
}

