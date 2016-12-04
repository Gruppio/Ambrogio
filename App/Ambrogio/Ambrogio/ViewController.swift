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
    
    var command: String?
    let particleURLString = "https://api.particle.io/v1/devices/1a002b000447343337373737/execute"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        command = Bundle.main.object(forInfoDictionaryKey: "Command") as? String
        titleLabel.text = Bundle.main.object(forInfoDictionaryKey: "Title") as? String
        descriptionLabel.text = Bundle.main.object(forInfoDictionaryKey: "Description") as? String
        sendRequest()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        titleLabel.alpha = 0
        descriptionLabel.alpha = 0
        activityIndicator.alpha = 0
        textView.alpha = 0
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        UIView.animate(withDuration: 0.5) {
            self.titleLabel.alpha = 1
            self.descriptionLabel.alpha = 1
            self.activityIndicator.alpha = 1
            self.textView.alpha = 1
        }
    }
    
    @IBAction func didTapTheScreen(_ sender: Any) {
        sendRequest()
    }
    
    private func sendRequest() {
        resetView()
        guard let command = command else {
            failure("Nil Command")
            return
        }
        
        guard let particleURL = URL(string: particleURLString) else {
            failure("Invalid Particle URL")
            return
        }
        let body = "arg=\(command)&access_token=\(accessToken)"
        
        let urlRequest = NSMutableURLRequest(url: particleURL)
        urlRequest.httpMethod = "POST"
        urlRequest.httpBody = body.data(using: String.Encoding.utf8)
        urlRequest.timeoutInterval = 5
        activityIndicator.startAnimating()
        URLSession.shared.dataTask(with: urlRequest as URLRequest) { (data, response, error) in
            guard error == nil else {
                self.failure(error?.localizedDescription ?? "")
                return
            }
            self.success()
        }.resume()
    }
    
    private func failure(_ message: String = "") {
        UIView.animate(withDuration: 0.5) {
            self.view.backgroundColor = UIColor(colorLiteralRed: 231/255, green: 76/255, blue: 60/255, alpha: 1)
            self.textView.text = message
        }
        activityIndicator.stopAnimating()
    }
    
    private func success(_ message: String = "") {
        UIView.animate(withDuration: 0.5) {
            self.view.backgroundColor = UIColor(colorLiteralRed: 46/255, green: 204/255, blue: 113/255, alpha: 1)
            self.textView.text = message
        }
        activityIndicator.stopAnimating()
    }
    
    private func resetView() {
        UIView.animate(withDuration: 0.5) {
            self.view.backgroundColor = UIColor(colorLiteralRed: 52/255, green: 152/255, blue: 219/255, alpha: 1)
            self.textView.text = ""
        }
        activityIndicator.stopAnimating()
    }
}

