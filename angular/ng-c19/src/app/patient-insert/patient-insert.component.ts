import { Component, OnInit } from '@angular/core';
import { FormBuilder, Validators } from '@angular/forms';

@Component({
  selector: 'app-patient-insert',
  templateUrl: './patient-insert.component.html',
  styleUrls: ['./patient-insert.component.scss']
})
export class PatientInsertComponent implements OnInit {



  constructor(private fb: FormBuilder) {}

    insertionForm = this.fb.group({
      name: ['', Validators.required],
      surname: ['', Validators.required],
      age: [''],
      covid: ['', Validators.required],
      country: [''],
      date: ['']
    })

  // insertionForm = new FormGroup({
  //   name: new FormControl(''),
  //   surname: new FormControl(''),
  //   age: new FormControl(''),
  //   covid: new FormControl(''),
  //   country: new FormControl(''),
  //   date: new FormControl('')
  // });

  ngOnInit(): void {
  }

}
